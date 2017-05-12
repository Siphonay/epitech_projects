/*
** error_handling.c for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 10:39:15 2016 Alexis Viguié
** Last update Sat Jan  9 19:42:51 2016 Alexis Viguié
*/

#include <stdio.h>
#include <stdlib.h>

void	exit_usage(char *ex_name)
{
  fprintf(stderr, "usage: %s archive_file file1 [file2 ... fileN]\n", ex_name);
  exit(1);
}

void	exit_mllc()
{
  perror("FATAL");
  exit(1);
}

void	exit_file_error(FILE **file_list, char *file_name)
{
  perror(file_name);
  free(file_list);
  exit(1);
}
