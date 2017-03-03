/*
** game_phase.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Wed Feb 01 10:36:11 2017 Benjamin BRIHOUM
** Last update Thu Feb 16 18:59:14 2017 Jean-Alexandre IBANEZ
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "get_next_line.h"

int	bad_input(char *str)
{
  if (!(str))
    {
      write (1, "\nwrong position\n", 16);
      return (0);
    }
  if (my_strlen(str) != 2)
    {
      write (1, "wrong position\n", 15);
      return (0);
    }
  else if ((str[0] >= 'A' && str[0] <= 'H') ||
	   (str[0] >= 'a' && str[0] <= 'h'))
    {
      if ((str[1] >= '1' && str[1] <= '8'))
	return (1);
    }
  else if ((str[0] >= '1' && str[0] <= '8'))
    {
      if ((str[1] >= 'A' && str[1] <= 'H') || (str[1] >= 'a' && str[1] <= 'h'))
	return (1);
    }
  write (1, "wrong position\n", 15);
  return (0);
}

void	end_your_turn(int pid, char *str)
{
  t_coord	atk;

  my_printf("%s: ", str);
  atk = transfo_points(str[0], str[1]);
  g_pid_second.mape[atk.x][atk.y] = 'Z';
  send_signals(pid, str[0], str[1]);
}

void		your_turn(int pid)
{
  struct sigaction	act;
  char		temp;
  char		*str;

  act.sa_handler = &sig_hdl;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
  write (1, "\nattack: ", 9);
  str = get_next_line(0);
  while (bad_input(str) == 0)
    {
      write (1, "attack: ", 8);
      str = get_next_line(0);
    }
  if (str[0] >= '1' && str[0] <= '8')
    {
      temp = str[0];
      str[0] = str[1];
      str[1] = temp;
    }
  if (str[0] >= 'a' && str[0] <= 'h')
    str[0] = str[0] - 32;
  end_your_turn(pid, str);
}

int			enemy_turn()
{
  int			i;
  struct sigaction	act;

  i = 0;
  act.sa_sigaction = &handler_sig;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_SIGINFO;
  my_printf("\nwaiting for enemy’s attack...\n");
  sigaction(SIGUSR1, &act, NULL);
  sigaction(SIGUSR2, &act, NULL);
  while (i < 6)
    {
      pause();
      i++;
    }
  return (0);
}

void	end_of_turn()
{
  my_printf("\nmy positions:\n");
  disp_map(g_pid_second.map);
  my_printf("\nenemy's positions:\n");
  disp_map(g_pid_second.mape);
}
