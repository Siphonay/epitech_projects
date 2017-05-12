/*
** sum_stdarg.c for sum stdarg in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov  5 15:47:28 2015 Alexis Viguié
** Last update Thu Nov  5 17:03:30 2015 Alexis Viguié
*/

#include <stdarg.h>
#include "my.h"

int		sum_stdarg(int i, int nb, ...)
{
  va_list	argslist;
  int		counter;
  int		result;

  va_start(argslist, nb);
  counter = 0;
  result = 0;
  if (i == 0)
    {
      while (counter < nb)
	{
	  result = result + va_arg(argslist, int);
	  counter++;
	}
    }
  else if (i == 1)
    {
      while (counter < nb)
	{
	  result = result + my_strlen(va_arg(argslist, char*));
	  counter++;
	}
    }
  else
    return (-1);
  return (result);
}
