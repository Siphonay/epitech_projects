##
## Makefile<my_archive> for my tar in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Sat Jan  9 12:03:24 2016 Alexis Viguié
## Last update Sun Jan 10 00:37:53 2016 Alexis Viguié
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra -Werror -ansi -pedantic
CFLAGS	+= -I include/

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

SRC	+= src/main.c \
	   src/error_handling.c \
           src/extract_archive.c

OBJ	+= $(SRC:.c=.o)

NAME	= my_unarchive

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
