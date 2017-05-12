##
## Makefile for my popup in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Mon Nov 30 14:36:22 2015 Alexis Viguié
## Last update Mon Nov 30 14:56:28 2015 Alexis Viguié
##

SRC=		my_popup.c \
		my_str_fnc.c

OBJ=		$(SRC:.c=.o)

INCLUDES=	my_popup.h

LDFLAGS=	-I$(INCLUDES) -lncurses

LCFLAGS=	-Wall -Wextra

RM=		rm -f

CC=		gcc -c

OC=		gcc

NAME=		my_popup

all:		$(NAME)

$(NAME):
	$(CC) $(SRC) $(LCFLAGS)
	$(OC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
