/*
** simple_list.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 18:32:31 2017 Alexis Viguié
** Last update Thu Jan  5 19:49:27 2017 Alexis Viguié
*/

#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

unsigned int	list_get_size(t_list list)
{
  unsigned int	counter;
  t_node	*list_copy;

  counter = 0;
  list_copy = (t_node *)&list;
  while (list_copy->next)
    {
      list_copy = list_copy->next;
      counter++;
    }
  return (counter);
}

t_bool	list_is_empty(t_list list)
{
  if (!list)
    return (TRUE);
  else
    return (FALSE);
}

void		list_dump(t_list list)
{
  t_node	*list_copy;

  list_copy = (t_node*)&list;
  while (list_copy->next)
    {
      printf("%f\n", list_copy->value);
      list_copy = list_copy->next;
    }
}

t_bool		list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	*new_front;
  t_node	new_node;

  new_front = front_ptr;
  new_node.value = elem;
  new_node.next = front_ptr;
  front_ptr = (t_list)&new_node;
  return (TRUE);
}

t_bool		list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_node	*list_copy;
  t_list	new_node;

  list_copy = (t_node)front_ptr;
  new_node.value = elem;
  new_node.next = NULL;
  if (front_ptr)
    {
      while (list_copy->next)
	list_copy = list_copy->next;
      list_copy->next = &new_node;
    }
  else
    front_ptr = &new_node;
  return (TRUE);
}

t_bool		add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  t_list	*list_copy;
  t_list	*next_node_copy;
  t_list	new_node;
  unsigned int	counter;

  if (!position)
    return (add_elem_at_front(front_ptr, elem));
  list_copy = front_ptr;
  new_node.value = elem;
  counter = 0;
  while (counter < (position - 1) && list_copy)
    {
      list_copy->next = list_copy;
      counter++;
    }
  if (!list_copy)
    return (FALSE);
  if (list_copy->next)
    new_node.next = list_copy->next->next;
  else
    new_node.next = NULL;
  list_copy->next = new_node;
  return (TRUE);
}

t_bool	list_del_elem_at_front(t_list *front_ptr)
{
  if (!front_ptr)
    return (FALSE);
  front_ptr = front_ptr->next;
  return (TRUE);
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list	*list_copy;

  if (!front_ptr)
    return (FALSE);
  if (!front_ptr->next)
    {
      front_ptr = front_ptr->next;
      return (TRUE);
    }
  else
    {
      list_copy = front_ptr;
      while (list_copy->next->next)
	list_copy = list_copy->next;
      list_copy->next = NULL;
    }
}

double	list_get_elem_at_front(t_list list)
{
  if (!list)
    return (0);
  return (list.value);
}

double		list_get_elem_at_back(t_list list)
{
  t_list	*list_copy;

  if (!list)
    return (0);
  list_copy = &list;
  while (list_copy->next)
    list_copy = list_copy->next;
  return (list_copy->value);
}

double		list_get_elem_at_position(t_list list, unsigned int position)
{
  t_list	*list_copy;
  unsigned int	counter;

  if (!list)
    return (0);
  list_copy = &list;
  counter = 0;
  while (counter < position && list_copy)
    {
      list_copy = list_copy->next;
      counter++;
    }
  if (list_copy)
    return (list_copy->value);
  else
    return (0);
}

t_node		*list_get_first_node_with_value(t_list list, double value)
{
  t_list	*list_copy;

  if (!list)
    return (NULL);
  list_copy = &list;
  while (list_copy->next && list_copy->next->value != value)
    list_copy = list_copy->next;
  return (list_copy->next);
}
