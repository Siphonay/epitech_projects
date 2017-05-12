/*
** fasta_free_struct_seqs.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 19:08:00 2016 Alexis Viguié
** Last update Tue Jun 21 11:07:22 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "fasta.h"

void	free_struct_seqs(struct s_seq *seqs)
{
  while (seqs->next)
    seqs = seqs->next;
  while (seqs->prev)
    {
      if (seqs->next)
	free(seqs->next);
      free(seqs->name);
      free(seqs->contents);
      seqs = seqs->prev;
    }
  free(seqs->name);
  free(seqs->contents);
  free(seqs);
}
