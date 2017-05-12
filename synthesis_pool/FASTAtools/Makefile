##
## Makefile for FASTAtools in /home/sam
## 
## Made by Alexis Viguié
## Login   <sam@epitech.net>
## 
## Started on  Mon Jun 20 10:18:02 2016 Alexis Viguié
## Last update Mon Jun 20 20:01:56 2016 Alexis Viguié
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

SRC	=	$(SRCDIR)fasta_main.c			\
		$(SRCDIR)fasta_get_stdin.c		\
		$(SRCDIR)fasta_error.c			\
		$(SRCDIR)fasta_build_sequences.c	\
		$(SRCDIR)fasta_capitalize.c		\
		$(SRCDIR)fasta_free_struct_seqs.c	\
		$(SRCDIR)fasta_dnasec.c			\
		$(SRCDIR)fasta_rnasec.c			\
		$(SRCDIR)fasta_revcom.c			\
		$(SRCDIR)fasta_kmlist.c			\
		$(SRCDIR)fasta_codseq.c			\
		$(SRCDIR)fasta_aalist.c			\
		$(SRCDIR)fasta_aligns.c

OBJ	=	$(SRC:.c=.o)

NAME	=	FASTAtools

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
