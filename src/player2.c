/*
** j2.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Tue Jan 31 12:11:38 2017 Benjamin BRIHOUM
** Last update Sun Feb 19 09:57:58 2017 Jean-Alexandre IBANEZ
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

void	sig_hdl(int signo)
{
  t_coord	missed_or_hit;
  static int	i = 0;

  missed_or_hit = z_point(g_pid_second.mape);
  if (signo == SIGUSR2)
    {
      my_printf("missed\n");
      g_pid_second.mape[missed_or_hit.x][missed_or_hit.y] = 'o';
    }
  else if (signo == SIGUSR1)
    {
      i++;
      my_printf("hit\n");
      g_pid_second.mape[missed_or_hit.x][missed_or_hit.y] = 'x';
    }
  if (i == 14)
    g_pid_second.pid = -2;
}

int			player2(char *pos, int pid1)
{
  t_maps		maps;
  struct sigaction	act;

  act.sa_handler = &sig_hdl;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  if ((kill(pid1, SIGUSR2)) == -1)
    return (84);
  my_printf("my_pid: %d\n", getpid());
  my_printf("successfully connected\n\n");
  maps = start(pos);
  g_pid_second.map = maps.map;
  g_pid_second.mape = maps.mape;
  while (g_pid_second.pid != -1 && g_pid_second.pid != -2)
    {
      enemy_turn();
      if (g_pid_second.pid == -1 || g_pid_second.pid == -2)
	return (disp_end());
      your_turn(pid1);
      if (g_pid_second.pid == -1 || g_pid_second.pid == -2)
	return (disp_end());
      usleep(1000);
      end_of_turn();
    }
  return (disp_end());
}
