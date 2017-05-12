/*
** sous_fonction.c for sous_fonction.c in /home/terrakorx/rendu/PSU_2016_malloc
**
** Made by champi_n
** Login   <terrakorx@epitech.net>
**
** Started on  Thu Feb 02 15:13:38 2017 champi_n
** Last update Sat Feb 11 17:23:05 2017 Alexis Viguié
*/

#include "malloc.h"

void	*malloc_nobase(t_block last, size_t s, t_block b)
{
  return (b = extend_heap(last, s));
}

void	*fonction(t_block nul, size_t s, t_block b)
{
  return (b = extend_heap(nul, s));
}

void	*pointeur_null(void *new_pointeur, size_t s, t_block b, void *p)
{
  if (b->next && b->next->free &&
      (b->size + BLOCK_SIZE + b->next->size) >= s)
    {
      fusion(b);
      if (b->size - s >= (BLOCK_SIZE + 4))
  split_block(b, s);
    }
  else
    {
      new_pointeur = malloc(s);
      if (new_pointeur == NULL)
  return (NULL);
      new_pointeur = get_block(new_pointeur);
      copy_block(b, new_pointeur);
      free(p);
      return (new_pointeur);
    }
  return (p);
}


void		copy_block(t_block src, t_block dst)
{
  int		*sdata;
  int		*ddata;
  size_t	i;

  sdata = src->ptr;
  ddata = dst->ptr;
  i = 0;
  while (i * 4 < src->size && i * 4 < dst->size)
    {
      ddata[i] = sdata[i];
      i++;
    }
}
