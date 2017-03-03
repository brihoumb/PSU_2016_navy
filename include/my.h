/*
** my.h for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/include
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Mon Jan 30 13:41:48 2017 Benjamin BRIHOUM
** Last update Thu Feb 16 16:06:00 2017 Jean-Alexandre IBANEZ
*/

#ifndef MY_H_
#define MY_H_

#include <signal.h>

#define LETTER (0)
#define NUMBER (1)
#define END (42)

typedef struct	s_coord
{
  int	x;
  int	y;
}		t_coord;

typedef struct	s_maps
{
  char	**map;
  char	**mape;
}		t_maps;

typedef struct	s_dev
{
  char	**map;
  char	**mape;
  int	pid;
}		t_dev;

extern t_dev	g_pid_second;

void	sig_hdl(int signo);
void	missed_hit(int signo);
void    sig_handler(int signo, siginfo_t *info,
		    void __attribute__((__unused__)) *context);
void    handler_sig(int signum, siginfo_t *info, void *context);
int     enemy_turn();
void     your_turn(int pid);
int     loose_win(char **map);
t_coord	transfo_points(char letter, char number);
int     error_navyfile(char *path);
char	**put_boats(char **map, char *path);
char	**full_map();
void	free_map(char **map);
void	disp_help();
void	my_printf(char *str, ...);
int	my_strlen(char *str);
int     compare(char *env, char *str);
char	*inverted_getnbr(int nb);
int	player1(char *pos);
int	player2(char *pos, int pid1);
int	my_getnbr(char *str);
char	bin_to_dec(int *bin, int nb);
int	*dec_to_bin(char dec);
void	disp_map(char **str);
t_maps	start(char *pos);
void    send_signals(int pid, char letter, char number);
void	end_of_turn();
t_coord		z_point(char **map);
int		disp_end();

#endif
