/*
** list.c for list in /home/pain_v/rendu/Colles/colle3
**
** Made by Vincent
** Login   <pain_v@epitech.net>
**
** Started on  Thu Dec 10 14:03:40 2015 Vincent
** Last update Thu Dec 10 15:56:27 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "poker.h"

void		list_push_front(t_list **list, char *str)
{
  t_list	*new_elem;
  t_list	*first_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return;
  first_elem = *list;
  *list = new_elem;
  new_elem->name = str;
  new_elem->dealer = 1;
  if (*list == NULL)
    {
      new_elem->next = NULL;
      new_elem->prec = NULL;
    }
  else
    {
      new_elem->prec = NULL;
      new_elem->next = first_elem;
    }
}

void		list_push_back(t_list **list, char *str)
{
  t_list	*new_elem;
  t_list	*last_elem;

  if ((new_elem = malloc(sizeof(t_list))) == NULL)
    return;
  last_elem = *list;
  while (last_elem->dealer != 1)
    last_elem = last_elem->next;
  new_elem->name = str;
  new_elem->dealer = 0;
  new_elem->prec = last_elem->prec;
  new_elem->next = last_elem;
  last_elem->prec = new_elem;
}

void	aff_list(t_list **list)
{
  t_list	*new_elem;

  new_elem = *list;
  if (list == NULL)
    return;
  while (new_elem->dealer != 1)
    new_elem = new_elem->next;
  my_putstr(new_elem->name);
  my_putstr("\n");
  new_elem = new_elem->next;
  while (new_elem->dealer != 1)
    {
      my_putstr(new_elem->name);
      my_putstr("\n");
      new_elem = new_elem->next;
    }
  my_putstr("\n");
}
