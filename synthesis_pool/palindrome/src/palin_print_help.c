/*
** palin_print_help.c for palindrome in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Jun 17 15:34:25 2016 Alexis Viguié
** Last update Fri Jun 17 15:35:26 2016 Alexis Viguié
*/

#include <stdio.h>
#include "palin.h"

int	palin_print_help(void)
{
  printf(HELP_MESSAGE);
  return (PALIN_EXIT_SUCCESS);
}
