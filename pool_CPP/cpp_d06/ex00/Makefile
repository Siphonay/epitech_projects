##
## Makefile for my_cat in /home/sam/Rendu/Piscine_CPP/cpp_d06/ex00
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Mon Jan  9 14:50:00 2017 Alexis Viguié
## Last update Mon Jan  9 14:59:03 2017 Alexis Viguié
##

ifeq ($(CLANG), yes)
	CC      = clang++
else
	CC	= g++
endif

RM    = rm -f

CPPFLAGS	+= -Wall -Wextra -Werror -std=c++03

ifeq ($(DEBUG), yes)
	CPPFLAGS += -g
endif

SRCDIR	+=	./

SRCS	+= 	$(SRCDIR)main.cpp

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	my_cat

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
