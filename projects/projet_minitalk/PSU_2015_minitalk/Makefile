##
## Makefile for minitalk in /home/sam/Rendu/Projets/projet_minitalk/PSU_2015_minitalk
## 
## Made by Alexis Viguié
## Login   <sam@epitech.eu>
## 
## Started on  Wed Feb 17 17:37:18 2016 Alexis Viguié
## Last update Thu Feb 18 11:17:53 2016 Alexis Viguié
##

ifeq ($(CLANG), yes)
	CC	=	clang
else
	CC	=	gcc
endif

RM		=	rm -rf

CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-Iinclude/

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-g
endif

SAMLSRC		+=	sam_lib/sam_bin_to_char.c \
			sam_lib/sam_str_to_int.c \
			sam_lib/sam_int_to_bin.c \
			sam_lib/sam_putstr.c \
			sam_lib/sam_strlen.c \
			sam_lib/sam_putnbr.c

SERVSRC		+=	src/server_main.c

CLNTSRC		+=	src/client_main.c \
			src/client_send.c \
			src/client_exit.c

SERVSRC		+=	$(SAMLSRC)
CLNTSRC		+=	$(SAMLSRC)

SERVOBJ		=	$(SERVSRC:.c=.o)

CLNTOBJ		=	$(CLNTSRC:.c=.o)

NAME	=	server
CLNTNAME	=	client

all:		$(NAME) $(CLNTNAME)

$(NAME):	$(SERVOBJ)
	$(CC) $(SERVOBJ) $(CFLAGS) -o $(NAME)

$(CLNTNAME):	$(CLNTOBJ)
	$(CC) $(CLNTOBJ) $(CFLAGS) -o $(CLNTNAME)

clean:
	$(RM) $(SERVOBJ)
	$(RM) $(CLNTOBJ)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(CLNTNAME)

re:		fclean all

.PHONY:		all $(NAME) $(CLNTNAME) clean fclean re
