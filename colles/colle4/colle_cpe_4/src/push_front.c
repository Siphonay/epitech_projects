/*
** push_front.c for push_front in /home/nwoumg_d/rendu/colle_cpe_4
**
** Made by nwoumg_d
** Login   <nwoumg_d@epitech.net>
**
** Started on  Fri Dec 18 09:14:04 2015 nwoumg_d
** Last update Fri Dec 18 10:06:40 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "list.h"

void            my_push_front(t_list **begin, char *data)
{
  t_list        *chaine;

  if ((chaine = malloc(sizeof(*chaine))) == NULL)
    exit(0);
  chaine->data = data;
  chaine->prev = NULL;
  chaine->next = NULL;
  *begin = chaine;
}
