/*
** malloc.c for malloc in /home/sam/Rendu/Projets/projet_malloc/malloc_test
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Feb  1 16:13:39 2017 Alexis Viguié
** Last update Sat Feb 11 17:22:05 2017 Alexis Viguié
*/

#include <unistd.h>
#include <sys/types.h>
#include "malloc.h"

t_block		extend_heap(t_block last, size_t s)
{
  t_block	b;

  b = sbrk(0);
  if (sbrk(BLOCK_SIZE + s) == (void*)-1)
    return (NULL);
  b->size = s;
  b->next = NULL;
  if (last)
    last->next = b;
  b->free = 0;
  return (b);
}

t_block	get_block(void *p)
{
  char	*tmp;
  tmp = p;
  return (p = tmp -= BLOCK_SIZE);
}

int	valid_addr(void *p)
{
  if (base)
    {
      if ((t_block)p > base && p < sbrk(0))
	return (p == (get_block(p))->ptr);
    }
  return (0);
}

t_block	fusion(t_block b)
{
  if (b->next && b->next->free)
    {
      b->size += BLOCK_SIZE + b->next->size;
      b->next = b->next->next;
      if (b->next)
	b->next->prev = b;
    }
  return (b);
}

void		*malloc(size_t size)
{
  t_block	b;
  t_block	last;
  size_t	s;

  b = base;
  s = align4(size);
  if (base)
    {
      last = base;
      b = find_block(&last, s);
      if (b)
	{
	  if ((b->size - s) >= (BLOCK_SIZE + 4))
	    split_block(b, s);
	  b->free = 0;
	}
      else
	if (!malloc_nobase(last, s, b))
  return (NULL);
    }
  else
    if (fonction(NULL, s, b) == NULL)
      return (NULL);
  return (b->data);
}
