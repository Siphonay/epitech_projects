/*
** push_back.c for push_back in /home/nwoumg_d/rendu/colle_cpe_4
**
** Made by nwoumg_d
** Login   <nwoumg_d@epitech.net>
**
** Started on  Fri Dec 18 09:16:49 2015 nwoumg_d
** Last update Fri Dec 18 10:06:28 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "list.h"

void            my_push_back(t_list **list, char *data)
{
  t_list        *chaine;
  t_list        *count;

  count = *list;
  if ((chaine = malloc(sizeof(*chaine))) == NULL)
    exit(0);
  chaine->next = NULL;
  chaine->data = data;
  while (count->next != NULL)
    count = count->next;
  count->next = chaine;
  chaine->prev = count;
}
