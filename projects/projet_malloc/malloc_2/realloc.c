/*
** realloc.c for realloc.c in /home/terrakorx/rendu/PSU_2016_malloc
**
** Made by champi_n
** Login   <terrakorx@epitech.net>
**
** Started on  Tue Feb 07 15:13:22 2017 champi_n
** Last update Sat Feb 11 17:22:34 2017 Alexis Viguié
*/

#include <unistd.h>
#include <sys/types.h>
#include "malloc.h"


void		*realloc(void *p, size_t size)
{
  size_t	s;
  t_block	b;
  void		*newp;

  newp = NULL;
  if (p == NULL)
    return (malloc(size));
  if (valid_addr(p))
    {

      s = align4(size);
      b = get_block(p);
      if (b->size >= s)
	{
	  if (b->size - s >= (BLOCK_SIZE + 4))
	    split_block(b, s);
	}
      else
	if (pointeur_null(newp, s, b, p) == NULL)
      return (NULL);
      return (p);
    }
  return (NULL);
}
