/*
** check_env.c for 42sh in /home/sam/Rendu/Projets/projet_42sh/PSU_2015_42sh/src/env_builtins
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu May 19 16:49:19 2016 Alexis Viguié
** Last update Fri Jun  3 15:16:23 2016 Alexis Viguié
*/

#include <string.h>

int	check_env(char *var_name, char **env_vars)
{
  int	counter;

  counter = 0;
  while (env_vars[counter])
    {
      if (!strncmp(var_name, env_vars[counter], strlen(var_name)))
	return (counter);
      counter++;
    }
  return (-1);
}
