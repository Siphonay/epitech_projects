##
## Makefile for Makefile in /home/joly_r/rendu/Colles/Colle2
## 
## Made by joly_r
## Login   <joly_r@epitech.net>
## 
## Started on  Tue May  3 14:02:29 2016 joly_r
## Last update Tue May  3 17:39:06 2016 Alexis Viguié
##

RM      = rm -f

CC      = gcc

CFLAGS  = -I./include/ -W -Wall -Wextra -Werror

DIR     = ./src/

NAME    = power4

SRC     = $(DIR)p4_loop.c \
	  $(DIR)p4_main.c \
	  $(DIR)p4_parser.c \
	  $(DIR)player_turn.c \
	  $(DIR)ia_turn.c \
	  $(DIR)p4_error.c \
	  $(DIR)check_board.c \
	  $(DIR)end_game.c \
	  $(DIR)utils.c \
	  $(DIR)utils_2.c

OBJ	=$(SRC:.c=.o)

all:    $(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all
