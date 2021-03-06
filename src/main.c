/*
** main.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Mon Jan 30 13:27:38 2017 Benjamin BRIHOUM
** Last update Mon Feb 13 13:46:06 2017 Benjamin BRIHOUM
*/

#include <fcntl.h>
#include <unistd.h>
#include "my.h"

t_dev     g_pid_second;

int	main(int ac, char **av)
{
  if (ac > 3 || ac < 2)
    return (84);
  else if (compare(av[1], "-h") == 0)
    disp_help();
  else if (ac == 2)
    {
      if (error_navyfile(av[1]) == 84)
	return (84);
      return (player1(av[1]));
    }
  else if (ac == 3)
    {
      if (error_navyfile(av[2]) == 84)
	return (84);
      return (player2(av[2], my_getnbr(av[1])));
    }
  return (0);
}
