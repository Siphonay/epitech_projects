/*
** get_next_line_functions.c for functions_line in /home/zaza/rendu/PSU_2015_minishell2/SRCS/get_next_line/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 17:38:02 2016 thibault derbre
** Last update Mon Apr  4 17:54:07 2016 thibault derbre
*/

#include "get_next_line.h"

void	go_to_zero(int *cmp, ssize_t *read_check, char *wait)
{
  *cmp = 0;
  *read_check = 0;
  free(wait);
}

char	*loop_read(t_getline *getline, char *wait, int *cmp,
		   ssize_t *read_check)
{
  while ((getline->i = rimka(wait, *cmp, *read_check)) == -1)
    {
      if ((getline->line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
	return (NULL);
      my_mem_set(&(getline->line), (READ_SIZE + 1));
      if ((*read_check = read(getline->fd, getline->line, READ_SIZE)) == -1)
	return (NULL);
      wait = my_strcat_get(wait, getline->line);
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
