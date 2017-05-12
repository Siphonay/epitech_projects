/*
** env_errors.c for 42sh in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Jun  3 17:21:47 2016 Alexis Viguié
** Last update Sun Jun  5 16:23:30 2016 Alexis Viguié
*/

#include <stdio.h>
#include "mysh.h"

int	print_unsetenv_usage()
{
  printf("%s: %s\n", UNSETENV, UNSETENV_USAGE);
  return (UNSETENV_NOVAR);
}

int	print_setenv_usage(char **env_vars)
{
  print_env(env_vars, env_vars);
  return (EXIT_SUCCESS);
}

int	invalid_env_name()
{
  printf("%s: %s\n", SETENV, SETENV_INVALID_VAR);
  return (ENV_EXIT_FAILURE);
}
