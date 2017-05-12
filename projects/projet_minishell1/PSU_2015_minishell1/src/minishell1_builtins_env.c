/*
** minishell1_builtins_env.c for minishell1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 20:46:56 2016 Alexis Viguié
** Last update Wed Jan 27 20:47:01 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"
#include "msh1.h"

int	find_env_var_index(char *var_name, char **ep)
{
  unsigned int	counter;

  counter = 0;
  while (ep[counter])
    {
      if (!sam_strncmp(ep[counter], var_name, sam_strlen(var_name)) &&
	  ep[counter][sam_strlen(var_name)] == '=')
	return (counter);
      counter++;
    }
  return (-1);
}

char	*build_env_var(char **input)
{
  char	*env_equal;
  char	*env_ret;

  if ((env_equal =
       sam_strncat(input[1], "=", 1)) == NULL)
    return (NULL);
  if ((env_ret =
       sam_strncat(env_equal, input[2], sam_strlen(input[2]))) == NULL)
    {
      free(env_equal);
      return (NULL);
    }
  free(env_equal);
  return (env_ret);
}

int	msh1_env_builtin_set(char **input, char **ep)
{
  char	*env_add;

  if (sam_strtablen(input) < 3)
    {
      sam_putstr_err(SETENV_USAGE);
      return (1);
    }
  if ((env_add = build_env_var(input)) == NULL)
    return (-1);
  if (find_env_var_index(input[1], ep) == -1)
    {
      if ((ep = sam_strtab_add(ep, env_add)) == NULL)
	{
	  free(env_add);
	  return (-1);
	}
    }
  else
    ep[find_env_var_index(input[1], ep)] = env_add;
  free(env_add);
  return (0);
}

int    	msh1_env_builtin_unset(char **input, char **ep)
{
  if (sam_strtablen(input) < 2)
    {
      sam_putstr_err(UNSETENV_USAGE);
      return (1);
    }
  if (find_env_var_index(input[1], ep) == -1)
    {
      sam_putstr_err(input[1]);
      sam_putstr_err(UNSETENV_ERR_NOTFOUND);
      return (1);
    }
  if ((ep = sam_strtab_rm(ep, find_env_var_index(input[1], ep))) == NULL)
    return (-1);
  return (0);
}

void		msh1_env_builtin_disp(char **ep)
{
  unsigned int	counter;

  counter = 0;
  while (ep[counter])
    {
      sam_putstr(ep[counter]);
      sam_putstr("\n");
      counter++;
    }
}
