/*
** main.c for bistro add test in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Oct 26 12:10:15 2015 Alexis Viguié
** Last update Tue Oct 27 10:34:54 2015 Alexis Viguié
*/

#include <stddef.h>
#include "my.h"
#include "addinf.h"

int	main(int ac, char **av)
{
  char	*result;

  if (ac == 3)
    {
      result = add_func(my_revstr(av[1]), my_revstr(av[2]));
      if (result == NULL)
	{
	  my_strerr("MALLOC ERROR!!!\n");
	  return (1);
	}
      else
	{
	  my_putstr(result);
	  my_putchar('\n');
	}
      return (0);
    }
  else
    {
      my_strerr(av[0]);
      my_strerr(": number1 number2\n");
      return (1);
    }
}
