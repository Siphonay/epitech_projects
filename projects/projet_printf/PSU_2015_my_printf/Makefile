##
## Makefile for bootstrap printf in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Thu Nov  5 16:19:47 2015 Alexis Viguié
## Last update Mon Nov 16 13:38:19 2015 Alexis Viguié
##

SRC=	my_printf.c \
	my_int_to_base_str.c \
	my_printf.c \
	my_putarg.c \
	my_putstr.c \
	my_strlen.c

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
