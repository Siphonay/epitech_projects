##
## Makefile for test language in /home/sam/Rendu/Projets/projet_tetris/test_language
## 
## Made by Alexis Viguié
## Login   <sam@epitech.eu>
## 
## Started on  Tue Mar  1 16:15:33 2016 Alexis Viguié
## Last update Tue Mar  1 17:32:39 2016 Alexis Viguié
##

CC =	gcc

RM =	rm -rf

TEST_LANG ?= en

ifneq ($(shell test -d strings/$(TEST_LANG)/; echo $$?),0)
  $(warning Language $(TEST_LANG) not implemented. Defaulted to en.)
  override TEST_LANG = en
endif

CFLAGS =	-Istrings/$(TEST_LANG)/

SRC =	language.c

OBJ =	$(SRC:.c=.o)

NAME =	test_language

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
