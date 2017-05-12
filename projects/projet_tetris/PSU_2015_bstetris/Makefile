##
## Makefile for bstetris in /home/sam/Rendu/Projets/projet_tetris/PSU_2015_bstetris
## 
## Made by Alexis Viguié
## Login   <sam@epitech.eu>
## 
## Started on  Mon Feb 22 17:09:36 2016 Alexis Viguié
## Last update Mon Feb 22 17:14:00 2016 Alexis Viguié
##

CC	=	gcc

RM	=	rm -rf

SRC	=	check_tetromino.c

OBJ	=	$(SRC:.c=.o)

NAME	=	check_tetrimino

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all $(NAME) clean fclean re
