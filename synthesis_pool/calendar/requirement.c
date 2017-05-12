/*
** requirement.c for calendar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jun 30 16:38:05 2016 Alexis Viguié
** Last update Fri Jul  1 15:57:18 2016 Alexis Viguié
*/

#include <stdlib.h>

typedef struct 	s_list
{
  void		*data;
  struct s_list *next;
}		t_list;

int	my_revlist_synthesis(t_list **begin)
{
  int	counter;

  counter = 0;
  if (!begin[counter])
    return (0);
  while (begin[counter + 1])
    counter++;
  while (counter)
    {
      begin[counter]->next = begin[counter - 1];
      counter--;
    }
  begin[counter]->next = NULL;
  return (0);
}

t_list		*my_findnodeeqinlist_synthesis(t_list *begin, void *data_ref,
				       int (*cmp)(void *, void *))
{
  t_list	*node_ret;

  node_ret = begin;
  if (!cmp(data_ref, node_ret->data))
    return (node_ret);
  while (node_ret->next && !(cmp(data_ref, node_ret->data)))
    node_ret = node_ret->next;
  if (!cmp(data_ref, node_ret->data))
    return (node_ret);
  else
    return (NULL);
}
