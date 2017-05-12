##
## Makefile for my_coktail in /home/le-mee_b/colle/colle_cocktail/
##
## Made by Boris Le Méec
## Login   <le-mee_b@epitech.net>
##
## Started on  Wed Dec 02 14:06:47 2015 Boris Le Méec
## Last update Thu Dec 10 16:00:44 2015 Alexis Viguié
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS  += -I./include/

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS =

SRCS	= src/main.c \
	src/struct.c \
	lib/my_getnbr.c \
	lib/my_str_fnc.c

OBJS	= $(SRCS:.c=.o)

NAME	= my_cocktail

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
