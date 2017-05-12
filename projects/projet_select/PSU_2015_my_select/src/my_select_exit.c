/*
** my_select_exit.c for my select in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Dec 13 19:38:31 2015 Alexis Viguié
** Last update Sun Dec 13 22:38:26 2015 Alexis Viguié
*/

#include <ncurses.h>
#include "sam.h"

void	print_select_exit(char **av, int *index, int ac)
{
  int	counter;
  int	counter2;

  clear();
  endwin();
  counter = 1;
  while (counter < ac)
    {
      counter2 = counter;
      if (index[counter] == 1)
	{
	  sam_putstr(av[counter]);
	  counter2++;
	  while ((index[counter2] != 1) && (counter2 < ac))
	    counter2++;
	  if (counter2 == ac)
	    sam_putstr("\n");
	  else
	    sam_putstr(" ");
	}
      counter++;
    }
}
