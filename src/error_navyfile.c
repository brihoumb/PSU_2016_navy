/*
** error_navyfile.c for navy in /home/ibanez_j/PSU_2016_navy/src
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Jan 31 21:22:04 2017 Jean-Alexandre IBANEZ
** Last update Thu Feb 16 14:57:56 2017 Jean-Alexandre IBANEZ
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	boats_size_ok(t_coord from, t_coord to, char *line)
{
  if (line[2] < 'A' || line[2] > 'H' || line[3] < '1' || line[3] > '8'
      || line[5] < 'A' || line[5] > 'H' || line[6] < '1' || line[6] > '8')
    return (84);
  if (from.x - to.x == 0)
    {
      if ((from.y - to.y) / 2 + 1 != line[0] - 48 &&
	  (from.y - to.y) / 2 - 1 != 0 - (line[0] - 48))
	return (84);
    }
  else
    {
      if (from.x - to.x + 1 != line[0] - 48 &&
	  from.x - to.x - 1 != 0 - (line[0] - 48))
	return (84);
    }
  return (0);
}

int	combo_error(char *line, t_coord from, t_coord to)
{
  from = transfo_points(line[2], line[3]);
  to = transfo_points(line[5], line[6]);
  if (line[1] != ':' || line[4] != ':')
    return (84);
  if (line[0] > 53 || line[0] < 50)
    return (84);
  if (boats_size_ok(from, to, line) == 84)
    return (84);
  return (0);
}

int	error_navyfile(char *path)
{
  int		same;
  int		i;
  t_coord	from;
  t_coord	to;
  char		line[8];
  int		fd;

  same = 0;
  i = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
    return (84);
  while (read(fd, line, 8) != 0)
    {
      if (combo_error(line, from, to) == 84)
	return (84);
      same = same + line[0] - 48;
      i++;
    }
  close (fd);
  if (same != 14)
    return (84);
  if (i != 4)
    return (84);
  return (0);
}
