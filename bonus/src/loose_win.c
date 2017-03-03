/*
** loose_win.c for navy in /home/ibanez_j/PSU_2016_navy/src
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Fri Feb  3 14:34:14 2017 Jean-Alexandre IBANEZ
** Last update Thu Feb 16 16:23:29 2017 Benjamin BRIHOUM
*/

#include "my.h"

int	loose_win(char **map)
{
  int	compt;
  int	i;
  int	y;

  compt = 0;
  i = 2;
  y = 2;
  while (i < 10)
    {
      while (y < 17)
	{
	  if (map[i][y] == 'x')
	    compt++;
	  y++;
	}
      y = 2;
      i++;
    }
  if (compt == 14)
    return (END);
  else
    return (-1);
}

int	disp_end()
{
  if (loose_win(g_pid_second.map) == END)
    {
      my_printf("\n\033[5;31mEnemy won\033[m\n");
      return (1);
    }
  my_printf("\n\033[5;32mI won\033[m\n");
  return (0);
}
