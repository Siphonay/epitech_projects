##
## Makefile for Makefile in /home/guillaume/Bureau/code/tp/unix/PSU_2015_tetris
## 
## Made by Guillaume Morin
## Login   <guillaume@epitech.net>
## 
## Started on  Thu Feb 25 11:51:52 2016 Guillaume Morin
## Last update Thu Mar  3 16:26:41 2016 Alexis Viguié
##

CC		=	gcc

RM		=	rm -rf

CFLAGS		+=	-Wall -Wextra
CFLAGS		+=	-I include/
CFLAGS		+=	-lncurses

TETRIS_LANG ?= en

ifneq ($(shell test -d strings/$(TETRIS_LANG)/; echo $$?),0)
  $(warning Language $(TETRIS_LANG) not implemented. Defaulted to en.)
  override TETRIS_LANG = en
endif

CFLAGS		+=	-I strings/$(TETRIS_LANG)/

ifeq ($(DEBUG), yes)
  CFLAGS += -g
endif

SRC	+=	src/tetris_main.c
SRC	+=	tetris_lib/tetris_putstr.c \
		tetris_lib/tetris_putnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
