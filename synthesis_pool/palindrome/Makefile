##
## Makefile for palindrome in /home/sam/Rendu/Piscine_S/palindrome
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Thu Jun 16 18:24:42 2016 Alexis Viguié
Last update Mon Jan  9 14:35:09 2017 Alexis Viguié
##

CC	=	clang

RM 	=	rm -f

ECHO	=	/bin/echo -e

DEFAULT	=	"\033[00m"

GREEN	=	"\033[1;32m"

RED     =       "\033[1;31m"

YELLOW	=	"\033[1;33m"

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

CFLAGS 	+=	-W -Wall -Wextra -Werror
CFLAGS 	+=	-I include/

LDFLAGS	=

SRCDIR	=	src/

SRC	=	$(SRCDIR)palin_main.c			\
		$(SRCDIR)palin_parse_options.c		\
		$(SRCDIR)palin_validate_options.c	\
		$(SRCDIR)palin_print_help.c		\
		$(SRCDIR)palin_sarah.c			\
		$(SRCDIR)palin_str_fncs.c		\
		$(SRCDIR)palin_aux.c

OBJ	=	$(SRC:.c=.o)

NAME	=	palindrome

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(CFLAGS) && \
	$(ECHO) "Compilation succeeded."

clean:
	@$(RM) $(OBJ) && \
	$(ECHO) $(YELLOW)"♺ "$(DEFAULT)$(OBJ:$(SRCDIR)%=%) && \
	$(ECHO) "Cleaned object files."

fclean:		clean
	@$(RM) $(NAME) && \
	$(ECHO) $(YELLOW)"♺ "$(DEFAULT)$(NAME) && \
	$(ECHO) "Cleaned binary."

re:		fclean all

%.o:		%.c
		@$(CC) -o $@ -c $< $(CFLAGS) && \
		$(ECHO) $(GREEN)"✓ "$(DEFAULT)$(<:$(SRCDIR)%=%)|| \
		$(ECHO) $(RED)"✗ "$(DEFAULT)$(<:$(SRCDIR)%=%)

.PHONY:		all clean fclean re
