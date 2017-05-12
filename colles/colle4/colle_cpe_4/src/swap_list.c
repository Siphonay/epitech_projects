/*
** swap_list.c for swap_list in /home/nwoumg_d/rendu/colle_cpe_4
**
** Made by nwoumg_d
** Login   <nwoumg_d@epitech.net>
**
** Started on  Fri Dec 18 09:28:18 2015 nwoumg_d
** Last update Fri Dec 18 10:48:51 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "list.h"

void		my_first(t_list **list, t_list *first, t_list *second)
{
  *list = second;
  first->next = second->next;
  first->prev = second;
  second->next = first;
  second->prev = NULL;
  (second->next)->prev = first;
}

void		last(t_list *first, t_list *second)
{
  first->next = NULL;
  first->prev = second;
  second->next = first;
  second->prev = first->prev;
}

void            list_swap(t_list **list, t_list *first, t_list *second)
{
  if (first->prev == NULL)
    my_first(list, first, second);
  else if (second->next == NULL)
    last(first, second);
  else
    {
      first->next = second->next;
      first->prev = second;
      second->next = first;
      second->prev = first->prev;
      (second->next)->prev = first;
    }
}
