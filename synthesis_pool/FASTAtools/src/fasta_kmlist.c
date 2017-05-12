/*
** fasta_kmlist.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 19:58:30 2016 Alexis Viguié
** Last update Mon Jun 20 19:59:23 2016 Alexis Viguié
*/

#include "fasta.h"

int	fasta_kmlist(struct s_fasta fastas)
{
  if (fastas.k < 0)
    return (FASTA_EXIT_FAILURE);
  return (FASTA_EXIT_SUCCESS);
}
