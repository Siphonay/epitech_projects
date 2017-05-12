/*
** builtin_setenv.c for 42sh in /home/sam/Rendu/Projets/projet_42sh/PSU_2015_42sh/src
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu May 19 13:58:43 2016 Alexis Viguié
** Last update	Sat Jun 04 16:24:29 2016 pedron_s
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "mysh.h"

char	*build_env(char *var_name, char *var_contents)
{
  char	*ret_var;

  if (!(ret_var = malloc(sizeof(char) * (strlen(var_name) + 2))) ||
      !(ret_var = strcpy(ret_var, var_name)))
	return (NULL);
  ret_var[strlen(var_name)] = ENV_VAR_SEPARATOR;
  ret_var[strlen(var_name) + 1] = '\0';
  if (var_contents)
    {
      if (!(ret_var = realloc(ret_var, sizeof(char) *
			      (strlen(var_name) + 2 + strlen(var_contents) + 1))) ||
	  !(ret_var = strcat(ret_var, var_contents)))
	return (NULL);
    }
  return (ret_var);
}

int	append_env(char *var_name, char *var_contents, char **env_vars)
{
  int	counter;

  counter = 0;
  while (env_vars[counter])
    counter++;
  if (!(env_vars[counter] = build_env(var_name, var_contents)))
    return (ENV_EXIT_FAILURE);
  env_vars[counter + 1] = NULL;
  return (EXIT_SUCCESS);
}

bool	check_validvar(char *var_name)
{
  int	counter;

  counter = 0;
  while (var_name[counter])
    {
      if (!counter)
	{
	  if (!(var_name[counter] >= 'A' && var_name[counter] <= 'Z') &&
	      !(var_name[counter] >= 'a' && var_name[counter] <= 'z') &&
	      var_name[counter] != '_')
	    return (false);
	}
      else
	{
	  if (!(var_name[counter] >= 'A' && var_name[counter] <= 'Z') &&
	      !(var_name[counter] >= 'a' && var_name[counter] <= 'z') &&
	      !(var_name[counter] >= '0' && var_name[counter] <= '9') &&
	      var_name[counter] != '_')
	    return (false);
	}
      counter++;
    }
  return (true);
}

int	builtin_setenv(char **av, char **env_vars, t_data *data)
{
  char *var_name;
  char *var_contents;
  int	env_pos;

  if (av[1])
    var_contents = av[2];
  else
    return (print_setenv_usage(env_vars));
  if (!check_validvar(var_name = av[1]))
    return (invalid_env_name());
  if ((env_pos = check_env(var_name, env_vars)) == -1)
    {
      if (!(env_vars = realloc(env_vars, sizeof(char*) *
			       (wordtablen(env_vars) + 2))) ||
	  append_env(var_name, var_contents, env_vars))
	return (ENV_EXIT_FAILURE);
    }
  else
    {
      free(env_vars[env_pos]);
      if (!(env_vars[env_pos] = build_env(var_name, var_contents)))
	return (ENV_EXIT_FAILURE);
    }
  data->env = env_vars;
  return (EXIT_SUCCESS);
}
