/*
** free.c for free.c in /home/terrakorx/rendu/PSU_2016_malloc
**
** Made by champi_n
** Login   <terrakorx@epitech.net>
**
** Started on  Tue Feb 07 15:09:28 2017 champi_n
** Last update Sat Feb 11 17:22:25 2017 Alexis Viguié
*/

#include <unistd.h>
#include <sys/types.h>
#include "malloc.h"

void		free(void *p)
{
  t_block	b;

  if (valid_addr(p))
    {
      b = get_block(p);
      b->free = 1;
      if (b->prev && b->prev->free)
	b = fusion(b->prev);
      if (b->next)
	fusion(b);
      else
	{
	  if (b->prev)
	    b->prev->next = NULL;
	  else
	    base = NULL;
	  brk(b);
	}
    }
}
