##
## Makefile for Red Alert in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.eu>
## 
## Started on  Tue Mar 15 09:56:38 2016 Alexis Viguié
## Last update Tue Mar 15 09:59:38 2016 Alexis Viguié
##

CC =		clang

RM =		rm -rf

CFLAGS +=	-Wall -Wextra
CFLAGS +=	-I include/

LDFLAGS =	-L/home/${USER}/.froot/lib/ -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

SRC = 		src/checkers_main.c \
		src/checkers_setcheckers.c

OBJ =		$(SRC:.c=.o)

NAME =		redalert_checkers

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
