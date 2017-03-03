##
## Makefile for navy in /home/brihoum_b/tek1/PSU_2016_navy
##
## Made by Benjamin Brihoum
## Login   <brihoum_b@epitech.net>
##
## Started on    30 01:21:51 PM2017 Benjamin Brihoum
## Last update Thu Feb 16 15:13:05 2017 Jean-Alexandre IBANEZ
##

SRC 	=  src/main.c		\
	   src/osef.c		\
	   src/help.c		\
	   src/inverted_getnbr.c\
	   src/full_map.c	\
	   src/player1.c	\
	   src/player2.c	\
	   src/getnbr.c		\
	   src/put_boats.c	\
	   src/error_navyfile.c	\
	   src/convert.c	\
	   src/get_next_line.c	\
	   src/loose_win.c	\
	   src/send_signals.c	\
	   src/game_phase.c	\
	   src/handling_signals.c

OBJ 	= $(SRC:.c=.o)

CFLAGS	= -I./include/ -L./lib -lmy -Wall -W -Wextra -g

CC 	= gcc

RM 	= rm -rf

NAME 	= navy

$(NAME): $(OBJ) subsystem
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

bonus:
	cd bonus && make

subsystem:
	cd lib && make

subsysclean:
	cd lib && make fclean

all:  $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean subsysclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean subsysclean subsystem bonus
