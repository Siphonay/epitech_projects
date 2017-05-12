/*
** freeelem.c for PSU_2015_42sh
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Wed Jun 01 21:47:14 2016 pedron_s
** Last update	Sat Jun 04 23:04:20 2016 pedron_s
*/

#include <stdlib.h>
#include <unistd.h>
#include "liste.h"

int		my_freechain(t_list *liste)
{
  t_elem	*elem;
  int		i;

  i = 0;
  if (liste->first != NULL)
    {
      elem = liste->first;
      while (elem)
	{
	  free(elem->prev);
	  while (elem->cmd[i])
	    free(elem->cmd[i++]);
	  elem = elem->next;
	}
      free(liste->last);
  }
  return (0);
}
