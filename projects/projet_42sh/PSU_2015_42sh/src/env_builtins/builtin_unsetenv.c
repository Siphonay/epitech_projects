/*
** builtin_unsetenv.c for 42sh in /home/sam/Rendu/Projets/projet_42sh/PSU_2015_42sh/src/env_builtins
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu May 19 16:46:07 2016 Alexis Viguié
** Last update Sat Jun  4 18:32:57 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysh.h"

char	**shift_var(char **env_vars, int var_pos)
{
  env_vars[var_pos] = env_vars[var_pos + 1];
  var_pos++;
  return (env_vars);
}

char	**clear_env_vars(char **env_vars)
{
  free_wordtab(env_vars);
  if ((env_vars = malloc(sizeof(char *))) == NULL)
      return (NULL);
  *env_vars = NULL;
  return (env_vars);
}

int	builtin_unsetenv(char **av, char **env_vars, t_data *data)
{
  int	var_pos;
  int	counter;

  counter = 1;
  if (wordtablen(av) < 2)
    return (print_unsetenv_usage());
  while (av[counter])
    {
      if ((var_pos = check_env(av[counter], env_vars)) >= 0)
	{
	  free(env_vars[var_pos]);
	  shift_var(env_vars, var_pos);
	  while (env_vars[var_pos])
	      env_vars = shift_var(env_vars, var_pos++);
	}
      else if (!strcmp(av[counter], "*"))
	{
	  if (!(env_vars = clear_env_vars(env_vars)))
	      return (ENV_EXIT_FAILURE);
	}
      counter++;
    }
  data->env = env_vars;
  return (EXIT_SUCCESS);
}
