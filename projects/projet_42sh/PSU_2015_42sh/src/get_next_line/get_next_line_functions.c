/*
** get_next_line_functions.c for get_next_line_functions in /home/zaza/rendu/PSU_2015_42sh/src/get_next_line/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed May  4 14:33:46 2016 thibault derbre
** Last update Wed May  4 14:39:55 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	go_to_zero(int *cmp, ssize_t *read_check, char *wait,
		   t_getline *getline)
{
  *cmp = 0;
  *read_check = 0;
  free(getline);
  free(wait);
}

char	*loop_read(t_getline *getline, char *wait, int *cmp,
		   ssize_t *read_check)
{
  while ((getline->i = check_read(wait, *cmp, *read_check)) == -1)
    {
      if ((getline->line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
	return (NULL);
      my_mem_set(&(getline->line), (READ_SIZE + 1));
      if ((*read_check = read(getline->fd, getline->line, READ_SIZE)) == -1)
	return (NULL);
      if ((wait = my_strcat_get(wait, getline->line)) == NULL)
	return (NULL);
      free(getline->line);
    }
  return (wait);
}

char	*get_started(t_getline *getline, char *wait, ssize_t *read_check)
{
  if ((wait = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  my_mem_set(&wait, (READ_SIZE + 1));
  if ((*read_check = read(getline->fd, wait, READ_SIZE)) == -1)
    return (NULL);
  return (wait);
}
