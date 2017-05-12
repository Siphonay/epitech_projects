/*
** my_list_size.c for my list size in /home/viguie_a/rendu_j11/tests
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct 12 13:56:59 2015 Alexis Viguié
** Last update Mon Oct 12 16:21:18 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "mylist.h"

int	my_list_size(t_list *begin)
{
  int	counter;

  counter = 0;
  while (begin != NULL)
    {
      begin = begin->next;
      counter++;
    }
  return (counter);
}
