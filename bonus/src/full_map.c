/*
** full_map.c for navy in /home/ibanez_j/PSU_2016_navy/src
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Tue Jan 31 10:39:54 2017 Jean-Alexandre IBANEZ
** Last update Thu Feb 16 16:22:18 2017 Benjamin BRIHOUM
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"

char	**full_map()
{
  char	**str;
  int	fd;
  char	*line;
  int	i;

  fd = open("map", O_RDONLY);
  i = 0;
  if ((str = malloc(sizeof(char*) * 11)) == NULL)
    return (NULL);
  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      str[i] = line;
      i++;
    }
  str[i] = NULL;
  close(fd);
  free(line);
  return (str);
}

void	free_map(char **map)
{
  int	i;

  i = 0;
  while (i < 10)
    {
      free(map[i]);
      i++;
    }
  free(map);
}

void	disp_map(char **str)
{
  int	i;

  i = 0;
  while (i < 10)
    {
      my_printf("\033[1;31m%s\033[m\n", str[i]);
      i++;
    }
}
