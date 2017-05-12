##
## Makefile for bsq in /home/sam/projet_bsq/CPE_2015_bsq
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Fri Dec 18 16:04:17 2015 Alexis Viguié
## Last update Mon Feb  8 16:53:55 2016 Alexis Viguié
##

ifeq ($(CLANG), yes)
	CC      = clang
else
	CC	= gcc
endif

RM      = rm -f

CFLAGS	+= -Wall -Wextra
CFLAGS  += -I include/

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS =

SRCS	+= 	src/main.c \
		src/bsq_exit.c \
		src/bsq_parse.c \
		src/bsq_disp.c

SRCS	+=	sam_lib/sam_get_nbr.c \
		sam_lib/sam_strfnc.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
