/*
** where.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Sun Jun  5 11:46:20 2016 Nolann Méléard
** Last update Sun Jun  5 16:16:32 2016 Nolann Méléard
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int	where(char **av, char **env, t_data *data)
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
      c = find_alias(av[j], data);
      i = search_path(env);
      len = strlen(env[i]) + strlen(av[j]);
      path = which_path(env[i], len);
      c = count_sep(env[i], ':');
      tab = fill_tab_where(len, c, path, av[j]);
      get_where(tab, c);
      j++;
    }
  return (0);
}
