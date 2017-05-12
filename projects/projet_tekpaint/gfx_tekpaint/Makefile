##
## Makefile for makefile in /home/theo/argent_t/rendu/gfx_tekpaint
## 
## Made by Théo Argentais
## Login   <theo@epitech.net>
## 
## Started on  Tue Jan  5 14:17:06 2016 Théo Argentais
## Last update Wed Jan  6 15:51:29 2016 Alexis Viguié
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wall -Wextra -Werror -ansi -pedantic
CFLAGS  += -I include/
CFLAGS 	+= -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS =

SRCS	+= 	src/main.c ## \ AJOUTEZ LES SRCS SUPPLÉMENTAIRES !!

OBJS	=	$(SRCS:.c=.o)

NAME	=	TekPaint

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
