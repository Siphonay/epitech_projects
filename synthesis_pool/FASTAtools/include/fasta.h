/*
** fasta.h for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 10:52:30 2016 Alexis Viguié
** Last update Tue Jun 21 10:42:43 2016 Alexis Viguié
*/

#ifndef FASTA_H_
# define FASTA_H_

# define FASTA_EXIT_SUCCESS 0
# define FASTA_EXIT_FAILURE 84

# define BUFFER_SIZE 2048
# define EMPTY_STR ""

# define MSG_INVALID_ARG "invalid arguments.\n"
# define MSG_HELP "USAGE\n\t" \
  "./FASTAtools option [k]\n\n" \
  "DESCRIPTION\n\t" \
  "options\t1:read FASTA from the standard input, write the DNA sequences to " \
  "the standard output\n\t\t" \
  "2:read FASTA from the standard input, write the RNA sequences to the stand" \
  "ard output\n\t\t" \
  "3:read FASTA from the standard input, write the reverse complement to the " \
  "standard output\n\t\t" \
  "4:read FASTA from the standard input, write the k-mer list to the standard" \
  "output\n\t\t" \
  "5:read FASTA from the standard input, write the coding sequences list to t" \
  "he standard output\n\t\t" \
  "6:read FASTA from the standard input, write the amino acids list to the st" \
  "andard output\n\t\t" \
  "7:read FASTA from the standard input containing exactly 2 sequences, align" \
  " them\n\t" \
  "k\tsize of the k-mers for option 4\n"
# define HELP_FLAG "-h"

# define STR_NAME_PREFIX '>'

struct	s_seq
{
  char		*name;
  char		*contents;
  struct s_seq	*prev;
  struct s_seq	*next;
};

struct	s_fasta
{
  int		k;
  struct s_seq	*seqs;
};

typedef int (*t_fp_fasta)(struct s_fasta);

int	fasta_dnasec(struct s_fasta fastas);
int	fasta_rnasec(struct s_fasta fastas);
int	fasta_revcom(struct s_fasta fastas);
int	fasta_kmlist(struct s_fasta fastas);
int	fasta_codseq(struct s_fasta fastas);
int	fasta_aalist(struct s_fasta fastas);
int	fasta_aligns(struct s_fasta fastas);

char		*get_stdin(void);
struct s_seq	*build_sequences(char *input);
char		*str_capitalize(char *str);
void		free_struct_seqs(struct s_seq *seqs);

int	print_iarg_error(void);
int	print_usage(void);

#endif /* !FASTA_H_ */
