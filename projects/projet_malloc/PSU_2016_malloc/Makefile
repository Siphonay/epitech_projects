##
## Makefile for Makefile in /home/terrakorx/rendu/PSU_2016_malloc
##
## Made by champi_n
## Login   <terrakorx@epitech.net>
## Started on  Wed Feb 01 17:25:10 2017 champi_n
## Last update Wed Feb 01 18:37:33 2017 champi_n

SHELL = /bin/sh
CC    = gcc
FLAGS        = -std=gnu99 -Iinclude
CFLAGS       = -fPIC -pedantic -Wall -Wextra -march=native -ggdb3

SOURCES = 	malloc.c \
						sous_fonction.c \
						realloc.c \
						free.c \
						modif_block.c

OBJECTS = $(SOURCES:.c=.o)


TARGET  = libmy_malloc.so

all: $(TARGET)

$(TARGET): $(OBJECTS)
			$(CC) $(FLAGS) $(CFLAGS) -shared -o $(TARGET) $(OBJECTS)

clean:
		        rm -f $(OBJECTS) $(TARGET)

fclean: clean
			rm -f $(NAME)

re:     fclean all
