##
## Makefile for makefile in /home/zaza/rendu/PSU_2015_minishell2/
##
## Made by thibault derbre
## Login   <derbre_t@epitech.eu>
##
## Started on  Mon Apr  4 17:16:07 2016 thibault derbre
## Last update Tue Apr 12 18:47:23 2016 thibault derbre
##

CC	=	gcc

NAME	=	mysh

src	=	src/main.c \
			src/base.c \
			src/table.c \
			src/init_env.c \
			src/my_sh.c \
			src/init_var.c \
			src/get_next_line/get_next_line_functions.c \
			src/get_next_line/get_next_line.c \
			src/show_prompt.c \
			src/strcmp_functions.c \
			src/parsing.c \
			src/parsing_bis.c \
			src/list.c \
			src/epur_str.c \
			src/prepare_exec.c \
			src/execution.c \
			src/builtins.c \
			src/setenv.c \
			src/setenv_bis.c \
			src/unsetenv.c \
			src/my_cd.c \
			src/my_cd_bis.c \
			src/my_cd_third.c \
			src/env.c \
			src/show_messages.c \
			src/my_exit.c \
			src/my_getnbr.c

OBJS	=	$(src:.c=.o)

RM	=	rm -rf

CFLAGS	+=	-W -Wall -Wextra

CFLAGS	+=	-I./include/

all:		library $(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

library:
		cd lib/my ; make -f Makefile

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
