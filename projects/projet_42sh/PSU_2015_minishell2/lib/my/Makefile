##
## Makefile for makefile in /home/zaza/rendu/PSU_2015_my_printf/lib/my/
##
## Made by Thibault Derbré
## Login   <derbre_t@epitech.eu>
##
## Started on  Mon Nov 16 10:46:47 2015 Thibault Derbré
## Last update Mon Apr 11 12:49:11 2016 thibault derbre
##

CC = gcc

RM = rm -f

NAME = libmy.a

CFLAGS = -Wextra -g -Wall -I./../../include

SRCS = my_put_nbr.c \
			 my_put_nbr_base.c \
			 my_put_nbr_un.c \
			 my_putchar.c \
			 my_putstr.c \
			 my_strlen.c \
			 my_putstr_cc.c \
			 my_put_nbr_base_cc.c

OBJS = $(SRCS:.c=.o)

all: compile library is cool

compile: $(OBJS)

library:
		ar rc $(NAME) $(OBJS)

is:
		ranlib $(NAME)

cool:
			mv libmy.a ../../

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) ../../libmy.a

re: fclean all

.PHONY: all clean fclean re
