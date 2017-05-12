/*
** env.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/env/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Mon May 16 16:47:26 2016 Nolann Méléard
** Last update Sun Jun  5 14:57:36 2016 Nolann Méléard
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mysh.h"

int	count_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    i++;
  return (i);
}

void	get_free_env(char **env)
{
  int	i;
  int	l;

  i = 0;
  l = count_env(env);
  while (i <= l)
    {
      free(env[i]);
      i++;
    }
  free (env);
}

void	print(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
   {
      printf("%s\n", env[i]);
      i++;
    }
}

char	**copy_env(char **src, char **env, int lines)
{
  int	i;
  int	len;

  i = 0;
  while (i != lines)
    {
      len = 0;
      len = strlen(src[i]);
      if ((env[i] = malloc(len * sizeof(char *))) == NULL)
	return (NULL);
      env[i] = memset(env[i], '\0', len);
      env[i] = strcpy(env[i], src[i]);
      i++;
    }
  env[i] = NULL;
  return (env);
}

char	**get_env(char **src)
{
  char	**env;
  int	i;

  i = count_env(src);
  if (i == 0)
    return (NULL);
  if ((env = malloc((i + 1) * sizeof(char *))) == NULL)
    return (NULL);
  env = copy_env(src, env, i);
  return (env);
}
