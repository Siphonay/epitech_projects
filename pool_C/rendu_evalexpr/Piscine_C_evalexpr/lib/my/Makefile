##
## Makefile for libmy in /home/viguie_a/rendu_j10/Piscine_C_J10/lib/my
## 
## Made by Alexis Viguié
## Login   <viguie_a@epitech.net>
## 
## Started on  Fri Oct  9 14:21:51 2015 Alexis Viguié
## Last update Wed Oct 14 18:59:14 2015 Alexis Viguié
##

SRC=	my_find_prime_sup.c \
	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_power_rec.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_sort_int_tab.c \
	my_square_root.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isprintable.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c

NAME=	libmy.a

OBJ=	$(SRC:.c=.o)

LIBD=	../

CC=	gcc -c

LC=	ar rc $(NAME)

MD=	mkdir -p

RM=	rm -f

all: $(NAME)

$(NAME): compsrc
	$(LC) $(OBJ)
	cp $(SRC) $(LIBD)
	cp $(NAME) $(LIBD)

compsrc:
	$(CC) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
