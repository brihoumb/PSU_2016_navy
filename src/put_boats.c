/*
** put_boats.c for navy in /home/ibanez_j/PSU_2016_navy/src
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Tue Jan 31 13:26:18 2017 Jean-Alexandre IBANEZ
** Last update Tue Feb 14 16:21:38 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"

t_coord		transfo_points(char letter, char number)
{
  t_coord	new_coord;
  char		a;

  a = 'A';
  new_coord.y = 2;
  while (letter != a)
    {
      new_coord.y = new_coord.y + 2;
      a++;
    }
  new_coord.x = 1 + number - 48;
  return (new_coord);
}

char	**if_x_equal(char **map, t_coord from, t_coord to, char line0)
{
  if (from.y - to.y < 0)
    {
      while (from.y <= to.y)
	{
	  map[from.x][from.y] = line0;
	  from.y = from.y + 2;
	}
    }
  else
    {
      while (from.y >= to.y)
	{
	  map[from.x][from.y] = line0;
	  from.y = from.y - 2;
	}
    }
  return (map);
}

char	**if_y_equal(char **map, t_coord from, t_coord to, char line0)
{
  if (from.x - to.x < 0)
    {
      while (from.x <= to.x)
	{
	  map[from.x][from.y] = line0;
	  from.x = from.x + 1;
	}
    }
  else
    {
      while (from.x >= to.x)
	{
	  map[from.x][from.y] = line0;
	  from.x = from.x - 1;
	}
    }
  return (map);
}

char	**complete_map(char ***map, t_coord from, t_coord to, char *line)
{
  if (from.x == to.x)
    (*map) = if_x_equal((*map), from, to, line[0]);
  else
    (*map) = if_y_equal((*map), from, to, line[0]);
  return (*map);
}

char	**put_boats(char **map, char *path)
{
  t_coord	from;
  t_coord	to;
  int	size_boat;
  int	fd;
  char	*line;

  line = malloc(sizeof(char) * 8);
  fd = open(path, O_RDONLY);
  while (read(fd, line, 8) != 0 && (size_boat = line[0] - 48))
    {
      if (line[2] >= 'A' && line[2] <= 'H')
	from = transfo_points(line[2], line[3]);
      else
	from = transfo_points(line[3], line[2]);
      if (line[5] >= 'A' && line[5] <= 'H')
	to = transfo_points(line[5], line[6]);
      else
	to = transfo_points(line[6], line[5]);
      map = complete_map(&map, from, to, line);
    }
  free(line);
  close(fd);
  return (map);
}
