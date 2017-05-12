/*
** disp_stdarg.c for disp stdarg in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov  5 15:56:28 2015 Alexis Viguié
** Last update Thu Nov  5 17:05:19 2015 Alexis Viguié
*/

#include <stdarg.h>
#include "my.h"

int		disp_stdarg(char *s, ...)
{
  va_list	arglist;
  int		counter;
  int		vaargres;

  va_start(arglist, s);
  counter = 0;
  while (s[counter] != '\0')
    {
      if (s[counter] == 'c')
	my_putchar(va_arg(arglist, int));
      else if (s[counter] == 's')
	my_putstr(va_arg(arglist, char*));
      else if (s[counter] == 'i')
	{
	  vaargres = va_arg(arglist, int);
	  my_put_nbr(vaargres);
	}
      else
	return (1);
      my_putchar('\n');
      counter++;
    }
  return (0);
}
