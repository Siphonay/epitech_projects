##
## Makefile for SBMLparser in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Mon Jun 13 09:46:11 2016 Alexis Viguié
## Last update Wed Jun 15 10:51:05 2016 Alexis Viguié
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

SRC	=	$(SRCDIR)str_lines_to_wordtab.c \
		$(SRCDIR)get_quoted_str.c \
		$(SRCDIR)append_to_wordtab.c \
		$(SRCDIR)help_message.c \
		$(SRCDIR)sbmlp_main.c \
		$(SRCDIR)parse_options.c \
		$(SRCDIR)sbml_error.c \
		$(SRCDIR)sbml_parsing.c \
		$(SRCDIR)free_wordtab.c

OBJ	=	$(SRC:.c=.o)

NAME	=	SBMLparser

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
