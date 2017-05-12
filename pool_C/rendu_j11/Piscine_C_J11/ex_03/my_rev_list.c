/*
** my_rev_list.c for my rev list in /home/viguie_a/rendu_j11/Piscine_C_J11/ex_03
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct 12 18:10:13 2015 Alexis Viguié
** Last update Mon Oct 12 18:40:27 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "mylist.h"

int		my_rev_list(t_list **begin)
{
  t_list	**rev;

  rev = malloc(sizeof(*rev));
  if (rev == NULL)
    return (1);
  while (*begin != NULL)
    {
      *rev = put_at_list_start(begin, begin->data);
      *begin = *begin->next;
    }
  begin = rev;
}

t_list		put_at_list_start(t_list **list, void *data)
{
  t_list	*elem;

  malloc(sizeof(*elem));
  if (elem == NULL)
    return (elem);
  elem->data = data;
  elem->next = *list;
  return (elem);
}
