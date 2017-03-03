/*
** j2.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Tue Jan 31 12:11:38 2017 Benjamin BRIHOUM
** Last update Thu Feb 16 16:27:35 2017 Benjamin BRIHOUM
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
  if (i == 0)
    {
      if (signo == SIGUSR2)
	{
	  my_printf("\033[31mmissed\033[m\n");
	  g_pid_second.mape[missed_or_hit.x][missed_or_hit.y] = 'o';
	}
      else if (signo == SIGUSR1)
	{
	  my_printf("\033[32mhit\033[m\n");
	  g_pid_second.mape[missed_or_hit.x][missed_or_hit.y] = 'x';
	}
    }
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
  my_printf("\033[1;33msuccessfully connected\033[m\n\n");
  maps = start(pos);
  g_pid_second.map = maps.map;
  g_pid_second.mape = maps.mape;
  while (loose_win(g_pid_second.map) != END &&
	 loose_win(g_pid_second.mape) != END)
    {
      enemy_turn();
      your_turn(pid1);
      usleep(1000);
      end_of_turn();
    }
  return (disp_end());
}
