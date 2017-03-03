/*
** inverted_getnbr.c for navy in /home/ibanez_j/PSU_2016_navy/src
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Mon Jan 30 19:19:36 2017 Jean-Alexandre IBANEZ
** Last update Mon Jan 30 19:47:58 2017 Benjamin BRIHOUM
*/

#include <unistd.h>
#include <stdlib.h>

char	*inverted_getnbr(int nb)
{
  int	value_malloc;
  int	mod;
  char	*result;
  int	temp_nb;

  value_malloc = 0;
  mod = 1;
  temp_nb = nb;
  while (nb > 10)
    {
      nb = nb / 10;
      mod = mod * 10;
      value_malloc++;
    }
  result = malloc(sizeof(char) * (value_malloc + 2));
  value_malloc = 0;
  while (mod != 0)
    {
      result[value_malloc] = temp_nb / mod + 48;
      temp_nb = temp_nb % mod;
      mod = mod / 10;
      value_malloc++;
    }
  result[value_malloc] = '\0';
  return (result);
}
