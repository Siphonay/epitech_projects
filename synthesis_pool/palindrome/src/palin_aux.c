/*
** palin_aux.c for palindrome in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jun 18 15:22:12 2016 Alexis Viguié
** Last update Sat Jun 18 16:47:44 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "palin.h"

void	aux_nosolution(bool solution)
{
  if (!solution)
    printf(MSG_NOSOLUTION);
}

bool	aux_print_number(t_options options, int nb, int counter)
{
  printf(MSG_ITERATIONS, options.value, nb, counter, options.base);
  return (true);
}

bool	aux_print_palindrome(t_options options, int counter, int counter2)
{
  printf(MSG_ITERATIONS, counter, options.value, counter2, options.base);
  return (true);
}

int	aux_free(char *s1, char *s2, int nb)
{
  free(s1);
  free(s2);
  return (nb + 1);
}
