/*
** send_signals.c for ,avy in /home/ibanez_j/PSU_2016_navy/src
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Fri Feb  3 16:18:27 2017 Jean-Alexandre IBANEZ
** Last update Sat Feb 11 11:55:28 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "my.h"

void	killing(int i, int *bin, int pid)
{
  if (bin[i] == 0)
    kill(pid, SIGUSR1);
  else if (bin[i] == 1)
    kill(pid, SIGUSR2);
  usleep(20000);
}

void	send_signals(int pid, char letter, char number)
{
  int	i;
  int	*bin_letter;
  int	*bin_number;

  i = 0;
  bin_letter = dec_to_bin(letter);
  bin_number = dec_to_bin(number);
  while (i < 3)
    {
      killing(i, bin_number, pid);
      i++;
    }
  i = 0;
  while (i < 3)
    {
      killing(i, bin_letter, pid);
      i++;
    }
  free(bin_number);
  free(bin_letter);
}
