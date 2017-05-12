/*
** fasta_error.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 17:36:23 2016 Alexis Viguié
** Last update Tue Jun 21 14:13:45 2016 Alexis Viguié
*/

#include <stdio.h>
#include "fasta.h"

int	print_iarg_error(void)
{
  fputs(MSG_INVALID_ARG, stderr);
  return (FASTA_EXIT_FAILURE);
}

int	print_usage(void)
{
  printf(MSG_HELP);
  return (FASTA_EXIT_SUCCESS);
}
