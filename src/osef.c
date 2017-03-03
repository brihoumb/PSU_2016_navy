/*
** osef.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Mon Jan 30 13:41:19 2017 Benjamin BRIHOUM
** Last update Sat Feb 11 11:45:51 2017 Jean-Alexandre IBANEZ
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a++;
  return (a);
}

int	compare(char *str, char *dump)
{
  int   a;

  a = 0;
  while (dump[a] == str[a])
    {
      if (dump[a] == '\0')
        return (0);
      a++;
    }
  return (1);
}

t_coord		z_point(char **map)
{
  int		a;
  int		b;
  t_coord	z;

  a = 0;
  b = 0;
  while (map[a][b] != 'Z')
    {
      if (map[a][b] == '\0')
	{
	  b = 0;
	  a++;
	}
      b++;
    }
  z.x = a;
  z.y = b;
  return (z);
}
