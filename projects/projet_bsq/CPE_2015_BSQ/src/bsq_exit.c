/*
** bsq_exit.c for bsq in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Dec 14 17:20:11 2015 Alexis Viguié
** Last update Fri Dec 18 16:42:27 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "sam.h"

void	exit_args(char *bin_name)
{
  sam_putstr_err("usage: ");
  sam_putstr_err(bin_name);
  sam_putstr_err(" filename\n");
  exit(1);
}

void	exit_file_not_found(char *filename)
{
  sam_putstr_err("error: failed to open ");
  sam_putstr_err(filename);
  write(1, "\n", 1);
  exit(2);
}

void	exit_incorrect_file(char *filecontents)
{
  free(filecontents);
  sam_putstr_err("error: invalid file contents\n");
  exit(3);
}

void	exit_mllc()
{
  sam_putstr_err("error: memory allocation failed\n");
  exit(42);
}
