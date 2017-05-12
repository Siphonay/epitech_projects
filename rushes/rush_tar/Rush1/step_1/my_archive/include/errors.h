/*
** errors.h<my_archive> for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Jan 10 00:27:17 2016 Alexis Viguié
** Last update Sun Jan 10 00:28:38 2016 Alexis Viguié
*/

#ifndef ERRORS_H_
# define ERRORS_H_

#include <stdio.h>

void	exit_usage(char *ex_name);
void	exit_mllc();
void	exit_file_error(FILE **file_list, char *file_name);

#endif /* !ERRORS_H_ */
