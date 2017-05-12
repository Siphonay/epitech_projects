##
## Makefile for my transformer in /home/sam/colle4/colle_cpe_4
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Fri Dec 18 10:54:24 2015 Alexis Viguié
## Last update Fri Dec 18 10:57:13 2015 Alexis Viguié
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS  += -I include/

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS =

SRCS	= 	src/last_char.c \
		src/my_alpha_sort.c \
		src/my_putstr.c \
		src/my_str_rotation.c \
		src/push_front.c \
		src/main.c \
		src/my_is_alpha.c \
		src/my_strlen.c \
		src/push_back.c \
		src/swap_list.c

OBJS	= $(SRCS:.c=.o)

NAME	= my_transformer

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
