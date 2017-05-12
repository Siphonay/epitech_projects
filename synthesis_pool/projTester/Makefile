##
## Makefile for projTester in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Thu Jun 23 15:16:27 2016 Alexis Viguié
## Last update Sat Jun 25 10:18:55 2016 Alexis Viguié
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

SRC	=	$(SRCDIR)projt_main.c	\
		$(SRCDIR)projt_trd.c

OBJ	=	$(SRC:.c=.o)

NAME	=	projTester

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
