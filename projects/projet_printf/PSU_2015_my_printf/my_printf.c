/*
** my_printf.c for my printf in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Nov  6 18:25:40 2015 Alexis Viguié
** Last update Mon Nov 16 23:36:01 2015 Alexis Viguié
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int	my_printf(char *format, ...)
{
  int		counter;
  va_list	arglist;

  va_start(arglist, format);
  counter = 0;
  while (format[counter])
    {
      if (format[counter] == '%')
	{
	  counter++;
	  if (format[counter] == 's')
	    my_putstr(va_arg(arglist, char*));
	  else if (format[counter] == 'S')
	    my_putstr_noimp(va_arg(arglist, char*));
	  else if (format[counter] == 'p')
	    my_putptr(va_arg(arglist, void*));
	  else
	    my_putarg(va_arg(arglist, int), format[counter]);
	}
      else
	write(1, &format[counter], 1);
      counter++;
    }
  return (0);
}
