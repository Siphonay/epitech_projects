/*
** fasta_rnasec.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 19:37:26 2016 Alexis Viguié
** Last update Tue Jun 21 10:38:20 2016 Alexis Viguié
*/

#include <stdio.h>
#include "fasta.h"

int	fasta_rnasec(struct s_fasta fastas)
{
  int	counter;

  while (fastas.seqs)
    {
      printf("%c%s\n", STR_NAME_PREFIX, fastas.seqs->name);
      counter = 0;
      while (fastas.seqs->contents[counter])
	{
	  if (fastas.seqs->contents[counter] == 'A' ||
	      fastas.seqs->contents[counter] == 'G' ||
	      fastas.seqs->contents[counter] == 'C' ||
	      fastas.seqs->contents[counter] == 'N')
	    fputc(fastas.seqs->contents[counter], stdout);
	  else if (fastas.seqs->contents[counter] == 'T')
	    fputc('U', stdout);
	  counter++;
	}
      fputc('\n', stdout);
      fastas.seqs = fastas.seqs->next;
    }
  return (FASTA_EXIT_SUCCESS);
}
