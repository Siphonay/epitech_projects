##
## Makefile for Makefile in /home/zaza/gkrellm/
##
## Made by thibault derbre
## Login   <thibault.derbre@epitech.eu>
##
## Started on  Sat Jan 21 16:01:09 2017 thibault derbre
## Last update Sun Jan 22 00:40:53 2017 sparepedago sparepedago
##

CXX		=	g++

NAME		=	gkrellm

RM		=	rm -f

DIR		=	src/

SRCS		=	$(DIR)main.cpp \
			$(DIR)Module.cpp \
			$(DIR)ModuleSys.cpp \
			$(DIR)ModuleName.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

CXXFLAGS		+=	-W -Wall -Wextra -std=c++03 -lncurses

CXXFLAGS		+=	-I./include/

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CFLAGS) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
