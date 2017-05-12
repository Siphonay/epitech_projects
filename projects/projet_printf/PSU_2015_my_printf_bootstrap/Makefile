##
## Makefile for bootstrap printf in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Thu Nov  5 16:19:47 2015 Alexis Viguié
## Last update Thu Nov  5 16:54:35 2015 Alexis Viguié
##

SRC=	my_putchar.c \
	my_putstr.c \
	my_put_nbr.c \
	my_strlen.c \
	sum_stdarg.c \
	disp_stdarg.c \

NAME=	libmy.a

OBJ=	$(SRC:.c=.o)

CC=	gcc -c

CFLAGS= -Wall -Wextra

LC=	ar rc $(NAME)

RM=	rm -f

all: $(NAME)

$(NAME): compsrc
	$(LC) $(OBJ)

compsrc:
	$(CC) $(CFLAGS) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
