/*
** please_sort_this_array.c for please sort this array in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov  5 11:43:21 2015 Alexis Viguié
** Last update Thu Nov  5 12:44:51 2015 Alexis Viguié
*/

#include "bootstrap.h"

void	please_sort_this_array(int *array, int size)
{
  int	counter;
  int	gotswapped;

  gotswapped = 1;
  while (gotswapped)
    {
      gotswapped = 0;
      counter = 0;
      while (counter < size)
	{
	  if ((array[counter + 1] != '\0') && (array[counter] > array[counter + 1]))
	    {
	      swap_elem(array, counter, counter + 1);
	      gotswapped = 1;
	    }
	  counter++;
	}
    }
}
