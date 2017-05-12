/*
** my_alpha_sort.c for my transformer in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 10:27:02 2015 Alexis Viguié
** Last update Fri Dec 18 10:50:33 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "list.h"

void		my_alpha_sort(t_list *list)
{
  t_list	*tmp;
  int		counter;
  int		was_swapped;

  was_swapped = 0;
  while (!(was_swapped))
    {
      was_swapped = 0;
      tmp = list;
      while (tmp->next != NULL)
	{
	  counter = 0;
	  while (tmp->data[counter] == tmp->next->data[counter])
	      counter++;
	  if (tmp->next->data[counter] > tmp->data[counter])
	    {
	      list_swap(&list, tmp, tmp->next);
	      was_swapped = 1;
	    }
	  tmp = tmp->next;
	}
    }
}
