/*
** fasta_main.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 10:50:24 2016 Alexis Viguié
** Last update Tue Jun 21 11:18:15 2016 Alexis Viguié
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fasta.h"

int	get_k(char *k_arg)
{
  int	int_ret;

  if (k_arg)
    int_ret = atoi(k_arg);
  else
    int_ret = -1;
  return (int_ret);
}

int			main(int ac, char **av)
{
  struct s_fasta	contents;
  t_fp_fasta		fasta_fncs[7];
  int			ret_val;

  if (!(av[1]) ||
      (atoi(av[1]) != 4 && ac != 2) || (atoi(av[1]) == 4 && ac != 3) ||
      (strcmp(av[1], HELP_FLAG) && (atoi(av[1]) < 1 || atoi(av[1]) > 7)))
    return (print_iarg_error());
  if (!strcmp(av[1], HELP_FLAG))
    return (print_usage());
  contents.k = get_k(av[2]);
  if (!(contents.seqs = build_sequences(get_stdin())))
    return (FASTA_EXIT_FAILURE);
  fasta_fncs[0] = fasta_dnasec;
  fasta_fncs[1] = fasta_rnasec;
  fasta_fncs[2] = fasta_revcom;
  fasta_fncs[3] = fasta_kmlist;
  fasta_fncs[4] = fasta_codseq;
  fasta_fncs[5] = fasta_aalist;
  fasta_fncs[6] = fasta_aligns;
  ret_val = fasta_fncs[atoi(av[1]) - 1](contents);
  free_struct_seqs(contents.seqs);
  return (ret_val);
}
