/*
** where.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Wed Jun  1 15:32:23 2016 Nolann Méléard
** Last update Sun Jun  5 15:42:25 2016 Nolann Méléard
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

char	**fill_tab_where(int len, int c, char *path, char *av)
{
  int	i;
  char	**tab;
  int	j;
  int	k;

  j = 0;
  i = 0;
  if ((tab = doublearray(c + 1, len)) == NULL)
    return (NULL);
  while (j != c)
    {
      k = 0;
      while (path[i] != ':' && path[i] != '\0')
	{
	  tab[j][k] = path[i];
	  k++;
	  i++;
	}
      tab[j] = endcopy(tab[j], k, av);
      if (path[i] == ':')
	i++;
      j++;
    }
  return (tab);
}

void	get_where(char **tab, int c)
{
  int	i;

  i = 0;
  while (i != c)
    {
      if ((access(tab[i], F_OK)) == 0)
	printf("%s\n", tab[i]);
      i++;
    }
}

int	find_alias(char *av, t_data *data)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  while (data->file[i].param != NULL && (strcmp(av, data->file[i].param)) != 0)
    i++;
  if (data->file[i].param == NULL)
    return (-1);
  if (i == -1)
    i = 0;
  printf("%s is an alias on ", data->file[i].param);
  while (data->file[i].tab[y] != NULL)
    {
      printf("%s ", data->file[i].tab[y]);
      y++;
    }
  printf("\n");
  return (0);
}

char	*which_path(char *env, int len)
{
  char	*path;

  if ((path = malloc((len - 4) * sizeof(char))) == NULL)
    return (NULL);
  path = memset(path, '\0', len - 4);
  path = my_strnncpy(path, env, 5);
  return (path);
}

int	which(char **av, char **env, t_data *data)
{
  char		*path;
  char		**tab;
  int		i;
  int		j;
  int		c;
  size_t	len;

  j = 1;
  while (av[j] != NULL)
    {
      if ((find_alias(av[j], data)) == -1)
	{
	  if ((i = search_path(env)) < 0)
	    return (1);
	  len = strlen(env[i]) + strlen(av[j]);
	  path = which_path(env[i], len);
	  c = count_sep(env[i], ':');
	  tab = fill_tab_where(len, c, path, av[j]);
	  get_where(tab, c);
	}
      j++;
    }
  return (0);
}
