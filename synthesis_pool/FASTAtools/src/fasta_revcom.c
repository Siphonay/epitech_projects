/*
** fasta_revcom.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 19:47:04 2016 Alexis Viguié
** Last update Tue Jun 21 15:25:24 2016 Alexis Viguié
*/

#include <string.h>
#include <stdio.h>
#include "fasta.h"

int	fasta_revcom(struct s_fasta fastas)
{
  int	counter;

  while (fastas.seqs)
    {
      printf("%c%s\n", STR_NAME_PREFIX, fastas.seqs->name);
      counter = strlen(fastas.seqs->contents);
      while (counter)
	{
	  if (fastas.seqs->contents[counter] == 'A')
	    fputc('T', stdout);
	  else if (fastas.seqs->contents[counter] == 'T')
	    fputc('A', stdout);
	  else if (fastas.seqs->contents[counter] == 'G')
	    fputc('C', stdout);
	  else if (fastas.seqs->contents[counter] == 'C')
	    fputc('G', stdout);
	  else if (fastas.seqs->contents[counter] == 'N')
	    fputc(fastas.seqs->contents[counter], stdout);
	  counter--;
	}
      fputc('\n', stdout);
      fastas.seqs = fastas.seqs->next;
    }
  return (FASTA_EXIT_SUCCESS);
}
