/*
** list2.c for list2 in /home/pain_v/rendu/Colles/colle3
**
** Made by Vincent
** Login   <pain_v@epitech.net>
**
** Started on  Thu Dec 10 14:27:27 2015 Vincent
** Last update Thu Dec 10 15:46:44 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "poker.h"

void	turn_dealer(t_list **list)
{
  t_list	*new_elem;

  new_elem = *list;
  while (new_elem->dealer != 1)
    new_elem = new_elem->next;
  new_elem->dealer = 0;
  new_elem = new_elem->next;
  new_elem->dealer = 1;
  return;
}

void	delete_list(t_list **list, char *str)
{
  t_list	*save;
  t_list	*tmp;
  t_list	*head;

  head = *list;
  tmp = head;
  while ((tmp->next)->name != str)
    tmp = tmp->next;
  save = tmp->next;
  tmp->next = tmp->next->next;
  free(save);
  *list = head;
}
