##
## Makefile for colle in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3
## 
## Made by Stanislav HEURTAULT
## Login   <heurta_s@epitech.net>
## 
## Started on  Tue May 10 19:08:44 2016 Stanislav HEURTAULT
## Last update Tue May 10 22:59:37 2016 Alexis Viguié
##

CC	=	gcc

SRC	=	src/main.c		\
		src/tekpixel.c		\
		src/noise.c		\
		src/getpixel.c		\
		src/load_grid.c		\
		src/init.c		\
		src/turn.c		\
		src/check.c		\
		src/add_random.c	\
		src/my_putstr.c		\
		src/game_512_check.c

LIB	=	-L/home/${USER}/.froot/lib/ -llapin \
		-L/usr/local/lib \
		-lsfml-audio \
		-lsfml-graphics \
		-lsfml-window \
		-lsfml-system \
		-lstdc++ -ldl \
		-lm


CFLAGS	+=	-I./include -W -Wall -Werror -Wextra

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

NAME	=	512

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
