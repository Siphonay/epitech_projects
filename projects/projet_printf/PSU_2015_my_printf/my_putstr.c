/*
** my_putstr.c for my printf in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Nov 13 16:52:11 2015 Alexis Viguié
** Last update Mon Nov 16 11:30:26 2015 Alexis Viguié
*/

#include <unistd.h>
#include "my.h"

void	my_putstr_noimp(char *str)
{
  int	counter;
  char	*noimp;

  counter = 0;
  while (str[counter] != '\0')
    {
      if (str[counter] < 32 || str[counter] >= 127)
	{
	  write(1, "\\", 1);
	  noimp = my_int_to_base_str(str[counter], OCTAL);
	  if (my_strlen(noimp) < 3)
	    {
	      if (my_strlen(noimp) < 2)
		write(1, "00", 2);
	      else
		write(1, "0", 1);
	    }
	  my_putstr(noimp);
	}
      else
	write(1, &str[counter], 1);
      counter++;
    }
}

void	my_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    {
      write(1, &str[counter], 1);
      counter++;
    }
}
