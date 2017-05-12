/*
** my_put_in_list.c for my put in list in /home/viguie_a/rendu_j11/tests
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct 12 13:50:06 2015 Alexis Viguié
** Last update Mon Oct 12 16:22:19 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "mylist.h"

int		my_put_in_list(t_list **list, void *data)
{
  t_list	*elem;
  t_list	*tmp;

  elem = malloc(sizeof(*elem));
  if (elem == NULL)
    return (1);
  elem->data = data;
  elem->next = NULL;
  if (*list == NULL)
    {
      *list = elem;
      return (0);
    }
  else
    {
      tmp = *list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = elem;
      return (0);
    }
}
