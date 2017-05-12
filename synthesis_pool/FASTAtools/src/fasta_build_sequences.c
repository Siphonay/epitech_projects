/*
** fasta_build_sequences.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 18:34:16 2016 Alexis Viguié
** Last update Tue Jun 21 10:50:28 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "fasta.h"

size_t		len_nl(char *str)
{
  size_t	ret_size;

  ret_size = 0;
  while (str[ret_size] && str[ret_size] != '\n')
    ret_size++;
  return (ret_size);
}

size_t		len_lt(char *str)
{
  size_t	ret_size;

  ret_size = 0;
  while (str[ret_size] && str[ret_size] != STR_NAME_PREFIX)
    ret_size++;
  return (ret_size);
}

struct s_seq	*append_seq(struct s_seq *cur_struct, char *name, char *contents)
{
  if (!cur_struct)
    {
      if (!(cur_struct = malloc(sizeof(struct s_seq))))
	return (NULL);
      cur_struct->prev = NULL;
    }
  else
    {
      if (!(cur_struct->next = malloc(sizeof(struct s_seq))))
	return (NULL);
      cur_struct->next->prev = cur_struct;
      cur_struct = cur_struct->next;
    }
  cur_struct->name = name;
  cur_struct->contents = (contents = str_capitalize(contents));
  cur_struct->next = NULL;
  return (cur_struct);
}

struct s_seq	*rewind_seq(struct s_seq *to_rewind, char *input)
{
  if (!to_rewind)
    return (NULL);
  while (to_rewind->prev)
    to_rewind = to_rewind->prev;
  free(input);
  return (to_rewind);
}

struct s_seq	*build_sequences(char *input)
{
  struct s_seq	*ret_seqs;
  char		*cur_name;
  char		*cur_cnt;
  int		counter;

  counter = 1;
  ret_seqs = NULL;
  while (input[counter])
    {
      while (input[counter - 1] != STR_NAME_PREFIX && input[counter])
	counter++;
      if (!(cur_name = malloc(sizeof(char) * (len_nl(&input[counter]) + 1))) ||
	  !(cur_name = memset(cur_name, 0, len_nl(&input[counter]) + 1)) ||
	  !(cur_name = strncpy(cur_name, &input[counter], len_nl(&input[counter]))))
	return (NULL);
      counter += len_nl(&input[counter]);
      if (!(cur_cnt = malloc(sizeof(char) * (len_lt(&input[counter]) + 1))) ||
	  !(cur_cnt = memset(cur_cnt, 0, len_lt(&input[counter]) + 1)) ||
	  !(cur_cnt = strncpy(cur_cnt, &input[counter], len_lt(&input[counter]))))
	return (NULL);
      counter += len_lt(&input[counter]);
      if (!(ret_seqs = append_seq(ret_seqs, cur_name, cur_cnt)))
	return (NULL);
    }
  return (rewind_seq(ret_seqs, input));
}
