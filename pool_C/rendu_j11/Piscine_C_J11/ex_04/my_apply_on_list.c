/*
** my_apply_on_list.c for my apply on list in /home/viguie_a/rendu_j11/Piscine_C_J11/ex_04
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct 12 21:07:41 2015 Alexis Viguié
** Last update Mon Oct 12 21:14:25 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "mylist.h"

int	my_apply_on_list(t_list *begin, int (*f)(void*))
{
  while (begin != NULL)
    {
      begin->data = f(begin->data);
      begin->next = begin;
    }
}
