/*
** exec4.c for 42 in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Tue May 31 14:10:48 2016 Nolann Méléard
** Last update Sun Jun  5 20:37:51 2016 Nolann Méléard
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "mysh.h"

char	*check_here(char **av)
{
  char	*path;
  int	len;

  if ((access(av[0], F_OK)) != 0)
    return (NULL);
  len = strlen(av[0]);
  if ((path = malloc((len + 1) * sizeof(char))) == NULL)
    return (NULL);
  path = strcpy(path, av[0]);
  return (path);
}

char	*my_memset(char *str, char c, int size)
{
  int	i;

  i = 0;
  while (i != size)
    {
      str[i] = c;
      i++;
    }
  return (str);
}

int	search_pwd(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if ((strncmp(env[i], "PWD=", 4)) == 0)
	return (i);
      i++;
    }
  return (-1);
}

char		*copy_arg(char	*path, char **av)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  if ((strncmp("./", av[0], 2)) == 0)
    j = 2;
  while (path[i] != '\0')
    i++;
  path[i] = '/';
  i++;
  while (j != (int)(strlen(av[0])))
    {
      path[i] = av[0][j];
      i++;
      j++;
    }
  return (path);
}

char	*get_dot_slash(char **av, char	**env)
{
  char	*path;
  int	i;
  int	len;

  len = 0;
  while (av[0][len] != '\0')
    {
      if (av[0][len] != '.')
	break;
      len++;
    }
  if (av[0][len] == '\0')
    return (NULL);
  if ((i = search_pwd(env)) == -1)
    return (NULL);
  if (av[0][0] != '.')
    return (NULL);
  len = strlen(env[i]), len = len + strlen(av[0]);
  if ((path = malloc((len - 3) * sizeof(char))) == NULL)
    return (NULL);
  path = memset(path, '\0', len - 3), path = my_strnncpy(path, env[i], 4);
  path = copy_arg(path, av);
  if ((access(path, F_OK)) != 0)
    return (NULL);
  return (path);
}
