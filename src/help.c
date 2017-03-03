/*
** help.c for navy in /home/ibanez_j/PSU_2016_navy/src
**
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
**
** Started on  Mon Jan 30 18:00:28 2017 Jean-Alexandre IBANEZ
** Last update Mon Jan 30 18:21:20 2017 Benjamin BRIHOUM
*/

#include <unistd.h>

void	disp_help()
{
  write(1, "USAGE\n", 6);
  write(1, "\t   ./navy [first_player_pid] navy_positions\n\n", 47);
  write(1, "DESCRIPTION\n", 12);
  write(1, "\t   first_player_pid\tonly for the 2nd player.  ", 47);
  write(1, "pid of the first player,\n\t   navy_positions\tfile", 48);
  write(1, " representing the positions of the ships.\n", 42);
}
