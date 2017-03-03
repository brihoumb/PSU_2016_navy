/*
** handling_signals.c for navy in /home/ibanez_j/PSU_2016_navy/src
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Sat Feb  4 11:13:15 2017 Jean-Alexandre IBANEZ
** Last update Thu Feb 16 16:22:56 2017 Benjamin BRIHOUM
*/

#include <signal.h>
#include "my.h"

void	transmut_points(int *bin_letter, int *bin_number, int pid)
{
  t_coord	atk_coo;
  char	letter;
  char	number;

  letter = bin_to_dec(bin_number, LETTER);
  number = bin_to_dec(bin_letter, NUMBER);
  my_printf("%c%c: ", letter, number);
  atk_coo = transfo_points(letter, number);
  if (g_pid_second.map[atk_coo.x][atk_coo.y] >= '2' &&
      g_pid_second.map[atk_coo.x][atk_coo.y]
      <= '5' && kill(pid, SIGUSR1) != -1)
    {
      my_printf("\033[32mhit\033[m\n");
      g_pid_second.map[atk_coo.x][atk_coo.y] = 'x';
    }
  else if (kill(pid, SIGUSR2) != -1)
    {
      my_printf("\033[31mmissed\033[m\n");
      g_pid_second.map[atk_coo.x][atk_coo.y] = 'o';
    }
}

void		handler_sig(int signum, siginfo_t *info,
			    void __attribute__((__unused__)) *context)
{
  static int	j = 0;
  static int	i = 0;
  int		bin_letter[3];
  int		bin_number[3];

  if (i < 3)
    {
      bin_letter[i] = (signum == SIGUSR1) ? 0 : 1;
      i++;
    }
  else
    {
      if (signum == SIGUSR1)
	bin_number[j] = 0;
      else if (signum == SIGUSR2)
	bin_number[j] = 1;
      j++;
    }
  if (i == 3 && j == 3)
    {
      transmut_points(bin_letter, bin_number, info->si_pid);
      i = 0;
      j = 0;
    }
}
