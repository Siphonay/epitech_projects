/*
** tek_arc.h for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 11:53:59 2016 Alexis Viguié
** Last update Tue Mar  1 15:59:33 2016 Alexis Viguié
*/

#ifndef TEK_ARC_H_
# define TEK_ARC_H_

# define MAGIC_SIZE 4
# define MAGIC_NUMBER "tek\0"

# include <stdio.h>

void	create_arc(FILE **file_list, char **args, int file_number);
void	close_flist(FILE **file_list, int filenum);

#endif /* !TEK_ARC_H_ */
