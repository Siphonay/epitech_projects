##
## Makefile for Makefile in /home/ruffetm/rendu/CPE/CPE_2015_Lemin
##
## Made by Mathieu RUFFET
## Login   <ruffetm@epitech.net>
##
## Started on  Tue Apr 12 15:28:18 2016 Mathieu RUFFET
## Last update Wed Apr 20 17:27:34 2016 Alexis Viguié
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I./include/ -Wall -Wextra -W

NAME	=	lem_in

SRCS	+=	lib_lemin/lemin_putstr.c \
		lib_lemin/lemin_strlen.c \
		lib_lemin/lemin_getline.c \
		lib_lemin/lemin_ll_fnc.c

SRCS	+=	src/lemin_main.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
