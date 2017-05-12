/*
** exec3.c for 42 in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Tue May 31 10:38:54 2016 Nolann Méléard
** Last update Sun Jun  5 22:14:50 2016 Nolann Méléard
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "mysh.h"

int	count_sep(char *str, char s)
{
  int	i;
  int	j;
  int	len;

  j = 0;
  i = 0;
  len = strlen(str);
  while (i < len)
    {
      if ((str[i] == s && str[i + 1] != s) || str[i + 1] == '\0')
	j++;
      i++;
    }
  return (j);
}

char	**doublearray(int x, int y)
{
  char	**sq;
  int	i;

  i = 0;
  if ((sq = malloc(sizeof(char *) * (x + 1))) == NULL)
    return (NULL);
  while (i != x)
    {
      if ((sq[i] = malloc(sizeof(char) * y)) == NULL)
	return (NULL);
      sq[i] = my_memset(sq[i], '\0', y);
      i++;
    }
  return (sq);
}

char	*endcopy(char *tab, int k, char *src)
{
  int	i;

  i = 0;
  tab[k] = '/';
  k++;
  while (src[i] != '\0')
    {
      tab[k] = src[i];
      i++;
      k++;
    }
  return (tab);
}

char	**fill_tab(char **tab, int c, char *path, char **av)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  i = 0;
  while (j != c)
    {
      k = 0;
      while (path[i] != ':' && path[i] != '\0')
	{
	  tab[j][k] = path[i];
	  k++;
	  i++;
	}
      tab[j] = endcopy(tab[j], k, av[0]);
      if (path[i] == ':')
	i++;
      j++;
    }
  return (tab);
}

int	get_access(char **tab, int c)
{
  int	i;

  i = 0;
  while (i != c)
    {
      if ((access(tab[i], F_OK)) == 0)
	return (i);
      i++;
    }
  return (-1);
}
