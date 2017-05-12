/*
** alias.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/conf_file/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Fri Jun  3 22:46:40 2016 Nolann Méléard
** Last update Sun Jun  5 11:31:57 2016 Nolann Méléard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "liste.h"
#include "mysh.h"

char	**copy_rest(char **av, int lines, char **tab)
{
  int	i;
  int	j;
  int	d;

  i = 2;
  d = 1;
  while (d != lines)
    {
      j = 0;
      while (av[i][j] != 39 && av[i][j] != '\0')
	{
	  tab[d][j] = av[i][j];
	  j++;
	}
      i++;
      d++;
    }
  return (tab);
}

  char	**cpy_alias_tab(char **av, int lines, char **tab)
{
  int	j;
  int	c;

  j = c = 0;
  while (av[1][j] != 39)
    j++;
  j++;
  while (av[1][j] != 39 && av[1][j] != '\0')
    {
      tab[0][c] = av[1][j];
      c++;
      j++;
    }
  if (lines != 1)
    tab = copy_rest(av, lines, tab);
  tab[lines] = NULL;
  return (tab);
}

char	**get_alias_tab(char **av)
{
  char	**tab;
  int	i;
  int	len;

  if ((i = count_for_alias(av)) == -1)
    return (NULL);
  len = count_len_tab(av);
  if ((tab = doublearray(i, len + 1)) == NULL)
    return (NULL);
  tab = cpy_alias_tab(av, i, tab);
  return (tab);
}

int	alias(char **av, char **env, t_data *data)
{
  int	i;

  i = 0;
  (void)env;
  if (av[1] == NULL)
    return (-1);
  data->file = count_and_realloc_file(data->file, &i);
  if ((data->file[i].param = get_name(av[1])) == NULL)
    return (-1);
  if ((data->file[i].tab = get_alias_tab(av)) == NULL)
    {
      free(data->file[i].param);
      data->file[i].param = NULL;
      dprintf(STDERR_FILENO, "alias : Syntax errors\n");
      return (-1);
    }
  return (0);
}

int	load_alias(char	**file, t_data *data)
{
  int	i;
  char	**av;

  i = 0;
  while (file[i] != NULL)
    {
      if ((strncmp(file[i], "alias ", 6)) == 0)
	{
	  av = my_str_to_wordtab(file[i], " ", 0, 0);
	  if ((alias(av, data->env, data)) == -1)
	    {
	      dprintf(STDERR_FILENO, "Error on .conf line %i\n", i + 1);
	      dprintf(STDERR_FILENO, "Usage: alias ll=%cls -l%c\n", 39, 39);
	      return (-1);
	    }
	}
      i++;
    }
  return (0);
}
