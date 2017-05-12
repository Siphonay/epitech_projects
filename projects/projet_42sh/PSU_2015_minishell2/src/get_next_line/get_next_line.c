/*
** get_next_line.c for get_next_line in /home/zaza/rendu/PSU_2015_minishell2/SRCS/get_next_line/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 17:37:50 2016 thibault derbre
** Last update Mon Apr  4 19:20:42 2016 thibault derbre
*/

#include "get_next_line.h"

void			my_mem_set(char **table, int size)
{
  int			i;

  i = 0;
  while (i < size)
    {
      (*table)[i] = '\0';
      i++;
    }
}

char			*my_strcpy(int i, char *str2, int *cmp)
{
  int			j;
  char			*str1;

  j = 0;
  if ((str1 = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  my_mem_set(&str1, (i + 1));
  if (str2[(*cmp)] == '\0')
    {
      return (NULL);
      free(str1);
    }
  while (str2[(*cmp)] != '\n')
    {
      if (str2[(*cmp)] == '\0')
	return (str1);
      str1[j] = str2[(*cmp)];
      j++;
      (*cmp)++;
    }
  (*cmp)++;
  return (str1);
}

char			*my_strcat_get(char *str1, char *str2)
{
  int			i;
  int			j;
  char			*res;

  j = -1;
  i = -1;
  while (str1[++i] != '\0');
  while (str2[++j] != '\0');
  if ((res = malloc(sizeof(char) * (i + j + 1))) == NULL)
    return (NULL);
  my_mem_set(&res, (i + j + 1));
  i = -1;
  j = 0;
  while (str1[++i] != '\0')
    res[i] = str1[j++];
  j = -1;
  while (str2[++j] != '\0')
    {
      res[i] = str2[j];
      i++;
    }
  return (res);
  free(str1);
}

int			rimka(char *str, int cmp, ssize_t read_check)
{
  if (read_check == 0)
    {
      while (str[cmp] != '\0')
	cmp++;
      return (cmp);
    }
  while (str[cmp] != '\n')
    {
      if (str[cmp] == '\0')
	return (-1);
      cmp++;
    }
  return (cmp);
}

char			*get_next_line(const int fd)
{
  t_getline		*getline;
  static char		*wait;
  static int		cmp;
  static ssize_t	read_check;

  if ((getline = malloc(sizeof(t_getline))) == NULL)
    return (NULL);
  getline->fd = fd;
 if (cmp == 0)
    {
      if ((wait = get_started(getline, wait, &read_check)) == NULL)
	return (NULL);
    }
  if ((wait = loop_read(getline, wait, &cmp, &read_check)) == NULL)
    return (NULL);
  if ((getline->buffer = my_strcpy(getline->i, wait, &cmp)) == NULL)
    {
      go_to_zero(&cmp, &read_check, wait);
      return (NULL);
    }
  return (getline->buffer);
}
