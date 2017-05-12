/*
** modif_block.c for modif_block.c in /home/terrakorx/rendu/PSU_2016_malloc
**
** Made by champi_n
** Login   <terrakorx@epitech.net>
**
** Started on  Tue Feb 07 15:15:44 2017 champi_n
** Last update Tue Feb 07 15:17:28 2017 champi_n
*/

#include <unistd.h>
#include <sys/types.h>
#include "malloc.h"


t_block		find_block(t_block *last, size_t size)
{
  t_block	b;

  b = base;
  while (b && !(b->free && b->size >= size))
    {
      *last = b;
      b = b->next;
    }
  return (b);
}

void		split_block(t_block b, size_t s)
{
  t_block	new;

  new = (t_block)b->data + s;
  new->size = b->size - s - BLOCK_SIZE;
  new->next = b->next;
  new->free = 1;
  b->size = s;
  b->next = new;
}
