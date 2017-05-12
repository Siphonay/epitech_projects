##
## Makefile for Makefile in /home/ruffet_m/rendu/CPE/CPE_2015_corewar
##
## Made by mathieu ruffet
## Login   <ruffet_m@epitech.net>
##
## Started on  Fri Feb 26 09:39:26 2016 mathieu ruffet
## Last update Wed Mar 30 19:58:30 2016 Victor Herlin
##

CC	=	gcc

RM	=	rm -f

MV	=	mv

NAME	=	./corewar/corewar
NAME2	=	./asm/asm

CFLAGS	=	-I./include -W -Wall

SRCS	=	corewar/main.c
SRCS2	=	asm/main.c \
		asm/file_getbuf.c \
		asm/my_tab.c \
		lib/my/my_str_to_wordtab.c \
		lib/my/my_putchar_putstr.c \
		lib/my/my_strlen.c \
		lib/my/my_strncmp.c

OBJS	=	$(SRCS:.c=.o)
OBJS2	=	$(SRCS2:.c=.o)

all:		COMPILE $(NAME)


COMPILE:
	@echo -e "\e[4;33mDO_IT,_JUST_DO_IT\e[0m"

$(NAME):	$(OBJS) $(OBJS2)
	@echo -e "\e[4;32m+ Compile\e[0m \e[1;34m$(NAME)\e[0m"
	$(CC)	$(OBJS) -o $(NAME) $(CFLAGS)
	@echo -e "\e[4;32m+ Compile\e[0m \e[1;34m$(NAME2)\e[0m"
	$(CC) $(OBJS2) -o $(NAME2) $(CFLAGS)
	@echo -e "\e[4;35mJOB'S_DOWN\e[0m"

clean:
		@echo -e "\e[4;35mREMOVE_AND_DESTROY,DO_IT_!!!\e[0m"
		@echo -e "\e[4;31m- Remove.o\e[0m"
		$(RM) $(OBJS)
		$(RM) $(OBJS2)
		@$(RM) /my_corewar/*~
		@$(RM) /my_asm/*~
		@$(RM) *~

fclean:		clean
	@echo -e "\e[4;31m- Remove\e[0m \e[1;34m$(NAME)\e[0m"
	$(RM) $(NAME)
	@echo -e "\e[4;31m- Remove\e[0m \e[1;34m$(NAME2)\e[0m"
	$(RM) $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
