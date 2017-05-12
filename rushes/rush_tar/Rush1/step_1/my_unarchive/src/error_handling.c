/*
** error_handling.c for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 19:28:24 2016 Alexis Viguié
** Last update Sat Jan  9 20:53:18 2016 Alexis Viguié
*/

#include <stdio.h>
#include <stdlib.h>

void	exit_usage(char *ex_name)
{
  fprintf(stderr, "usage: %s archive_file\n", ex_name);
}

void	exit_mllc()
{
  perror("FATAL");
  exit(1);
}

void	exit_file_error(char *file_name)
{
  perror(file_name);
  exit(1);
}

void	exit_invalid_arc(FILE *archive)
{
  fprintf(stderr, "error: invalid archive\n");
  fclose(archive);
  exit(1);
}
