##
## Makefile for makefile my cat in /home/viguie_a/rendu_j12/Piscine_C_J12/cat
## 
## Made by Alexis Viguié
## Login   <viguie_a@epitech.net>
## 
## Started on  Wed Oct 14 19:41:02 2015 Alexis Viguié
## Last update Wed Oct 14 19:53:52 2015 Alexis Viguié
##

SRC=		cat.c

NAME=		cat

OBJ=		$(SRC:.c=.o)

CFLAGS=		-Wextra -Wall -Werror

LDFLAGS=	-L../lib/ -lmy -I../include

CC=		gcc -c

OBJC=		gcc $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)

RM=		rm -f


all: $(NAME)

$(NAME):
	$(CC) $(SRC)
	$(OBJC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
