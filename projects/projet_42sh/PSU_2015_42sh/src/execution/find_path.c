/*
** exec2.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Wed May 25 14:29:40 2016 Nolann Méléard
** Last update	Sat Jun 04 22:27:31 2016 pedron_s
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

int	search_path(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (strncmp(env[i], "PATH=", 5) == 0)
	return (i);
      i++;
    }
  return (-1);
}

void	get_free_tab(char **tab, int y)
{
  int	i;

  i = 0;
  while (i != y)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

char	*real_path(char **tab, int ac, char *path, int c)
{
  path = memset(path, '\0', (strlen(path)));
  path = strcpy(path, tab[ac]);
  get_free_tab(tab, c);
  return (path);
}

char		*get_path(char **env, char **av)
{
  char		*path;
  char		**tab;
  int		i;
  int		c;
  int		access;
  size_t	len;

  if ((i = search_path(env)) < 0)
    return (NULL);
  len = (strlen(env[i])) + (strlen(av[0]));
  if ((path = malloc((len - 4) * sizeof(char))) == NULL)
    return (NULL);
  path = memset(path, '\0', len - 4);
  path = my_strnncpy(path, env[i], 5);
  c = count_sep(env[i], ':');
  tab = doublearray(c + 1, len);
  tab = fill_tab(tab, c, path, av);
  if ((access = get_access(tab, c)) != -1)
    {
      path = real_path(tab, access, path, c);
      return (path);
    }
  get_free_tab(tab, c);
  return (NULL);
}

char	**get_exec(char **av, char **env, t_data *data)
{
  char	*path;

  path = get_dot_slash(av, env);
  if (path == NULL)
    path = check_here(av);
  if (path == NULL)
    path = get_path(env, av);
  if (path == NULL)
    {
      data->exec = 1;
      dprintf(STDERR_FILENO, "%s: Command not found.\n", av[0]);
      return (env);
    }
  if ((data->exec = execve(path , av, env)) != -1)
    {
      data->exec = 1;
      dprintf(STDERR_FILENO, "%s: Problem while executing.\n", av[0]);
      free(path);
      return (env);
    }
  free(path);
  return (env);
}
