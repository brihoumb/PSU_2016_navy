/*
** j1.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Tue Jan 31 12:10:45 2017 Benjamin BRIHOUM
** Last update Sun Feb 19 09:57:41 2017 Jean-Alexandre IBANEZ
*/

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

void	sig_handler(int signo, siginfo_t *info,
		    void __attribute__((__unused__)) *context)
{
  t_coord	missed_or_hit;
  static int	i = 0;

  if (i == 0)
    {
      if (signo == SIGUSR2)
	{
	  my_printf("\nenemy connected\n\n", i++);
	  g_pid_second.pid = info->si_pid;
	}
    }
  else if (i == 1)
    {
      missed_or_hit = z_point(g_pid_second.mape);
      if (signo == SIGUSR2)
	{
	  my_printf("missed\n");
	  g_pid_second.mape[missed_or_hit.x][missed_or_hit.y] = 'o';
	}
      else if (signo == SIGUSR1)
	{
	  my_printf("hit\n");
	  g_pid_second.mape[missed_or_hit.x][missed_or_hit.y] = 'x';
	}
    }
}

t_maps		start(char *pos)
{
  t_maps	maps;

  maps.map = full_map();
  maps.mape = full_map();
  maps.map = put_boats(maps.map, pos);
  my_printf("my positions:\n");
  disp_map(maps.map);
  my_printf("\nenemy's positions:\n");
  disp_map(maps.mape);
  return (maps);
}

int	player1(char *pos)
{
  t_maps	maps;
  struct sigaction	act;

  act.sa_sigaction = &sig_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_SIGINFO;
  my_printf("my_pid: %d\n", getpid());
  my_printf("waiting for enemy connection...\n");
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
  pause();
  maps = start(pos);
  g_pid_second.map = maps.map;
  g_pid_second.mape = maps.mape;
  while (g_pid_second.pid != -1 && g_pid_second.pid != -2)
    {
      your_turn(g_pid_second.pid);
      if (g_pid_second.pid == -1 || g_pid_second.pid == -2)
	return (disp_end());
      enemy_turn();
      if (g_pid_second.pid == -1 || g_pid_second.pid == -2)
	return (disp_end());
      end_of_turn();
    }
  return (disp_end());
}
