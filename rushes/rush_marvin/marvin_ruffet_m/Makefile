##
## Makefile for Makefile in /home/ruffetm/rendu/RUSH/marvin_ruffet_m
##
## Made by Mathieu RUFFET
## Login   <ruffetm@epitech.net>
##
## Started on  Sat May 14 09:51:25 2016 Mathieu RUFFET
## Last update Sat May 14 17:38:03 2016 Alexis Viguié
##

CC	=	gcc

RM	=	rm -f

NAME	=	marvin

SRCS	=	srcs/main.c			\
		srcs/explain.c			\
		srcs/str_to_wordtab.c		\
		srcs/tablen.c			\
		srcs/type_detection.c		\
		srcs/disp_var.c			\
		srcs/remove_trailing_semicolon.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -ansi -pedantic -I./include

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		clean all

.PHONY:		all clean fclean re
