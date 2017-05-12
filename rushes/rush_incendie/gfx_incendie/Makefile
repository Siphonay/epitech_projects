##
## Makefile for make in /home/herlin_a/rendu/gfx_incendie
## 
## Made by Victor Herlin
## Login   <herlin_a@epitech.net>
## 
## Started on  Sat Dec  5 09:31:02 2015 Victor Herlin
## Last update Sun Dec  6 15:22:11 2015 Alexis Viguié
##

CC	=	gcc -o

RM	=	rm -f

CFLAGS	=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm -L/home/herlin_a/.froot/lib -llapin

NAME	=	gtfo

SRC	=	main.c \
		color_palette.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(OBJ) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
