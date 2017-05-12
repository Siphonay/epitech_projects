/*
** fasta_get_stdin.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 16:15:24 2016 Alexis Viguié
** Last update Tue Jun 21 15:18:57 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "fasta.h"

char		*get_stdin(void)
{
  char		*ret_str;
  int		read_size;
  int		read_pos;

  if (!(ret_str = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
    return (NULL);
  read_pos = 0;
  while ((read_size = read(0, &ret_str[read_pos], BUFFER_SIZE)) > 0)
    {
      read_pos += read_size;
      if (!(ret_str = realloc(ret_str, sizeof(char) *
			      (read_pos + BUFFER_SIZE + 1))))
	return (NULL);
    }
  ret_str[read_pos] = '\0';
  return (ret_str = realloc(ret_str, sizeof(char) * (read_pos + 1)));
}
