##
## Makefile for my_coktail in /home/le-mee_b/colle/colle_cocktail/
##
## Made by Boris Le Méec
## Login   <le-mee_b@epitech.net>
##
## Started on  Wed Dec 02 14:06:47 2015 Boris Le Méec
## Last update Sun Dec 13 22:43:12 2015 Alexis Viguié
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS  += -I./include/
CFLAGS	+= -lncurses

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS =

SRCS	= src/main.c \
	src/my_select_errors.c \
	src/my_select_exit.c \
	sam_lib/sam_strfnc.c

OBJS	= $(SRCS:.c=.o)

NAME	= my_select

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
