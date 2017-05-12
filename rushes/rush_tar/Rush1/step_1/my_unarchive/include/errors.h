/*
** errors.h<includes> for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 19:33:59 2016 Alexis Viguié
** Last update Sat Jan  9 20:01:03 2016 Alexis Viguié
*/

#ifndef ERRORS_H_
# define ERRORS_H_

#include <stdio.h>

void	exit_usage(char *ex_name);
void	exit_mllc();
void	exit_file_error(char *file_name);
void	exit_invalid_arc(FILE *archive);

#endif /* !ERRORS_H_ */
