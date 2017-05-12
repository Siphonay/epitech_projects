##
## Makefile for colle 3 in /home/sam/colle3/Piscine_C_colles-Semaine_03
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Sun Oct 25 02:46:47 2015 Alexis Viguié
## Last update Sun Oct 25 03:07:27 2015 Alexis Viguié
##

SRC=		main.c \
		glue_func.c \
		my_strerr.c

NAME=		what_glue

OBJ=		$(SRC:.c=.o)

INC_DIR=	include

CFLAGS=		-Wextra -Wall -Werror

LDFLAGS=	-I$(INC_DIR) -Llib -lmy

CC=		gcc -g -c $(LDFLAGS)

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
