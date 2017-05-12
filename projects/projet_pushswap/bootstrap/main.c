/*
** main.c for test in /home/sam/projet_pushswap/bootstrap
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Nov  3 17:22:41 2015 Alexis Viguié
** Last update Thu Nov  5 13:34:58 2015 Alexis Viguié
*/

#include <stdio.h>
#include "bootstrap.h"

void	print_int_array(int *array)
{
  int	counter;

  counter = 0;
  while (array[counter] != '\0')
    {
      if (counter)
	printf(", ");
      printf("%i", array[counter]);
      counter++;
    }
  printf("\n");
}

int	main()
{
  int	intarr[7] = {2, 7, 65, 98, 33, 41, 1};
  print_int_array(intarr);
  please_sort_this_array(intarr, 7);
  print_int_array(intarr);
  return (0);
}
