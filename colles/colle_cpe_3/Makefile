##
## Makefile for colle cocktail in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Thu Dec 10 15:31:18 2015 Alexis Viguié
## Last update Thu Dec 10 15:40:36 2015 Alexis Viguié
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS  += -I .

ifeq ($(DEBUG), yes)
	CFLAGS += -g
endif

LDFLAGS =

SRCS	= 	main.c \
		process_operation.c \
		my_strcmp.c \
		my_putstr.c \
		list1.c \
		list2.c

OBJS	= $(SRCS:.c=.o)

NAME	= my_poker

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
