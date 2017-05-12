##
## Makefile for makefile in /home/zaza/rendu/PSU_2015_42sh/
##
## Made by thibault derbre
## Login   <derbre_t@epitech.eu>
##
## Started on  Mon Apr 18 13:33:40 2016 thibault derbre
## Last update Sun Jun  5 22:49:09 2016 thibault derbre
##

NAME	=	42sh

DIR	=	src/

CC	=	gcc -g

SRCS	=	$(DIR)main.c 					\
		$(DIR)command.c 				\
		$(DIR)init_list.c 				\
		$(DIR)get_next_line/get_next_line.c 		\
		$(DIR)get_next_line/get_next_line_functions.c 	\
		$(DIR)epur_str/delete_token_spaces.c 		\
		$(DIR)epur_str/epur_str.c 			\
		$(DIR)base.c					\
		$(DIR)env.c					\
		$(DIR)which.c					\
		$(DIR)where.c					\
		$(DIR)echo/my_echo.c				\
		$(DIR)cd_builtin/my_cd.c			\
		$(DIR)cd_builtin/change_directory.c		\
		$(DIR)cd_builtin/remote_cd_directory.c		\
		$(DIR)cd_builtin/cd_old.c			\
		$(DIR)cd_builtin/cd_home.c			\
		$(DIR)execution/exec.c				\
		$(DIR)execution/utility.c				\
		$(DIR)execution/search_pwd.c				\
		$(DIR)execution/find_path.c				\
		$(DIR)env_builtins/check_env.c			\
		$(DIR)env_builtins/builtin_setenv.c		\
		$(DIR)env_builtins/builtin_printenv.c		\
		$(DIR)env_builtins/builtin_unsetenv.c		\
		$(DIR)env_builtins/env_errors.c			\
		$(DIR)exit_builtin/do_op.c			\
		$(DIR)exit_builtin/exit_builtin.c		\
		$(DIR)exit_builtin/my_getnbr.c			\
		$(DIR)listes/liste.c				\
		$(DIR)listes/freeelem.c				\
		$(DIR)listes/def.c				\
		$(DIR)listes/strtowordtab0.c 			\
		$(DIR)signal/signal.c				\
		$(DIR)conf_file/load.c				\
		$(DIR)conf_file/alias.c				\
		$(DIR)conf_file/count_realloc.c			\
		$(DIR)conf_file/get_name.c			\
		$(DIR)conf_file/export.c			\
		$(DIR)conf_file/make_alias.c			\
		$(DIR)display.c					\
		$(DIR)reading_pars/pars_tokens.c				\
		$(DIR)reading_pars/pipe.c					\
		$(DIR)reading_pars/table.c					\
		$(DIR)listes/init_liste.c \
		$(DIR)reading_pars/check_flow.c \
		$(DIR)reading_pars/check_tokens.c \
		$(DIR)reading_pars/exec_without_pipe.c \
		$(DIR)reading_pars/execute_flow.c \
		$(DIR)reading_pars/pipe_exec.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -rf

CFLAGS	+=	-I./include/ -W -Wall -Wextra

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"

BLUE	=	"\033[1;34m"

BLUE2	=	"\033[1;36m"

GREEN	=	"\033[1;32m"

RED     =       "\033[1;31m"

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS)
		@$(ECHO) "\n"$(BLUE2)"\t- Program Compiled -" $(DEFAULT)

clean:
		@$(RM) $(OBJS)
		@$(ECHO) $(BLUE2)"\nrm all .o\n" $(DEFAULT)
		@$(ECHO) $(BLUE2)"\n----------------------- 42sh -----------------------\n" $(DEFAULT)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

%.o:		%.c
		@$(CC) -o $@ -c $< $(CFLAGS) && \
		$(ECHO) $(GREEN)"   OK"$(DEFAULT) "--" $(BLUE)$< $(DEFAULT) || \
		$(ECHO) $(RED)"   KO"$(DEFAULT) "--" $(BLUE)$< $(DEFAULT)
