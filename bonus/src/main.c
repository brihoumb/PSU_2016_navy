/*
** main.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Mon Jan 30 13:27:38 2017 Benjamin BRIHOUM
** Last update Thu Feb 16 16:30:23 2017 Benjamin BRIHOUM
*/

#include <fcntl.h>
#include <unistd.h>
#include <SFML/Audio.h>
#include "my.h"

t_dev     g_pid_second;

int	main(int ac, char **av)
{
  sfMusic	*music;

  music = sfMusic_createFromFile("music.ogg");
  if (!music)
    return (84);
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
      sfMusic_play(music);
      return (player2(av[2], my_getnbr(av[1])));
    }
  return (0);
}
