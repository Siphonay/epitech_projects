/*
** init_liste.c for PSU_2015_42sh
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Sun Jun 05 11:36:29 2016 pedron_s
** Last update	Sun Jun 05 22:10:06 2016 pedron_s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"

void	initialisation_liste(t_list *liste)
{
  liste->size = 0;
  liste->first = NULL;
  liste->last = NULL;
  liste->temp = NULL;
}

t_elem	*my_addtolist(t_elem *elem)
{
  if ((elem->cmd[0] = realloc(elem->cmd[0], 3)) == NULL)
    return (NULL);
  elem->cmd[0][1] = elem->cmd[0][0];
  elem->cmd[0][2] = '\0';
  return (elem);
}

void		show_pos(t_list *liste, char *def)
{
  t_elem	*elem;

  free(def);
  elem = liste->first;
  while (elem)
    {
      my_check_id(elem);
      elem = elem->next;
    }
}

int	my_check(char *tab, char *def)
{
  int	val;

  val = 0;
  while (def[val] != '\0')
    {
      if (tab != NULL && tab[0] == def[val])
	{
	  return (1);
	}
      val++;
    }
  return (0);
}
