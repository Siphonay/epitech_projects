/*
** asm.h for asm.h in /home/ruffet_m/rendu/CPE/CPE_2015_corewar/include
**
** Made by mathieu ruffet
** Login   <ruffet_m@epitech.net>
**
** Started on  Fri Feb 26 09:56:23 2016 mathieu ruffet
** Last update Wed Mar 30 08:52:47 2016 Victor Herlin
*/

#ifndef ASM_H_
# define ASM_H_
# define READ_SIZE	(10)
#include "op.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

char	**file_getbuf_in_tab(int);
int	file_parsing(char*);
char	**my_str_to_wordtab(char*, char);
void	my_show_wordtab(char**);
int	my_strlen(char*);
void	my_putstr(char *);
void	my_putchar(char);
int	check_the_tab(char**);
int	my_strncmp(char*, char*, int);
char	**clean_tab_first_spaces(char**);

#endif /* !ASM_H_ */
