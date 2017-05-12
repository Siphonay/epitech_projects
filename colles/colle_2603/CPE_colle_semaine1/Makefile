##
## Makefile for  in /home/simon/colle_1_2603
##
## Made by Simon Pedrono
## Login   <simon@epitech.net>
##
## Started on  Tue Apr 26 14:06:01 2016 Simon Pedrono
## Last update Tue Apr 26 15:10:28 2016 Simon Pedrono
##

NAME	=	tree

SRCS	=	./srcs/main.c		\
		./srcs/pars.c		\
		./srcs/err.c		\
		./lib/my_getnbr.c	\
		./lib/my_putstr.c	\
		./srcs/disp_tree.c	\
		./lib/findL.c	\
		./lib/isnum.c	\
		./lib/my_putnb.c	\
		./lib/my_putchar.c	\
		./lib/strncmp.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc -I./include/

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
