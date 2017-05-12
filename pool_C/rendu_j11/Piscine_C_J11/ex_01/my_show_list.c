/*
** my_show_list.c for my show list in /home/viguie_a/rendu_j11/tests
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct 12 13:56:59 2015 Alexis Viguié
** Last update Mon Oct 12 16:22:46 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "mylist.h"

void		my_show_list(struct s_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      my_putstr("\n");
      tmp = tmp->next;
    }
}
