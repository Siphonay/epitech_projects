##
## Makefile for makefile in /home/viguie_a/rendu_j12/Piscine_C_J12/cat
## 
## Made by Alexis Viguié
## Login   <viguie_a@epitech.net>
## 
## Started on  Wed Oct 14 19:41:02 2015 Alexis Viguié
## Last update Tue Oct 20 14:28:38 2015 Alexis Viguié
##

SRC=		#INSERT SOURCES HERE

NAME=		evalexpr

OBJ=		$(SRC:.c=.o)

CFLAGS=		-Wextra -Wall -Werror

LDFLAGS=	-Llib/ -lmy -Iinclude/

CC=		gcc -g -c

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
