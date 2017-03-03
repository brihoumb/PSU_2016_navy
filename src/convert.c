/*
** convert.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Wed Feb 01 15:04:11 2017 Benjamin BRIHOUM
** Last update Thu Feb 16 14:55:48 2017 Jean-Alexandre IBANEZ
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	bin_to_dec(int *bin, int nb)
{
  if (nb == LETTER)
    return (bin[0] * 4 + bin[1] * 2 + bin[2] * 1 + 65);
  else if (nb == NUMBER)
    return (bin[0] * 4 + bin[1] * 2 + bin[2] * 1 + 1 + 48);
  return (0);
}

int	*dec_to_bin(char dec)
{
  int	*a;
  int	b;

  b = 0;
  a = malloc(sizeof(int) * 3);
  if ((dec - 49) < 10)
    b = dec - 49;
  else if ((dec - 65) < 10)
    b = dec - 65;
  a[2] = b % 2;
  a[1] = (b / 2) % 2;
  a[0] = (b / 4) % 2;
  return (a);
}
