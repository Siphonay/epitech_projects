##
## Makefile<my_archive> for my tar in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Sat Jan  9 12:03:24 2016 Alexis Viguié
## Last update Sat Jan  9 15:26:03 2016 Alexis Viguié
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
           src/create_arc.c \
	   src/close_flist.c

OBJ	+= $(SRC:.c=.o)

NAME	= my_archive

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
