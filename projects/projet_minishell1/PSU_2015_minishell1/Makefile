##
## Makefile<my_archive> for my tar in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Sat Jan  9 12:03:24 2016 Alexis Viguié
## Last update Wed Jan 27 23:38:42 2016 Alexis Viguié
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra -Werror -ansi -pedantic
CFLAGS	+= -I include/

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

SRC	+= src/minishell1_main.c \
	   src/minishell1_execute.c \
	   src/minishell1_exec_getpath.c \
	   src/minishell1_parse.c \
	   src/minishell1_builtins.c \
	   src/minishell1_exec_aux.c \
	   src/minishell1_builtins_env.c \
	   src/minishell1_getenv.c

SRC	+= sam_lib/sam_strlen.c \
	   sam_lib/sam_putstr.c \
	   sam_lib/sam_strcmp.c \
	   sam_lib/sam_strncmp.c \
	   sam_lib/sam_strncpy.c \
	   sam_lib/sam_strncat.c \
	   sam_lib/sam_get_nbr.c \
	   sam_lib/sam_gets.c \
	   sam_lib/sam_gets_aux_fnc.c \
	   sam_lib/sam_free_strtab.c \
	   sam_lib/sam_strtablen.c \
	   sam_lib/sam_strtab_add.c \
	   sam_lib/sam_strtab_rm.c \
	   sam_lib/sam_strtab.c \
	   sam_lib/sam_strtabcpy.c

OBJ	+= $(SRC:.c=.o)

NAME	= mysh

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
