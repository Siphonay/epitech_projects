/*
** builtin_printenv.c for 42sh in /home/sam/Rendu/Projets/projet_42sh/PSU_2015_42sh/src/env_builtins
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed May 25 09:09:46 2016 Alexis Viguié
** Last update Fri Jun  3 22:39:25 2016 Nolann Méléard
*/

#include <stdio.h>

int	print_env(char **av, char **env_vars)
{
  (void) av;
  int	counter;

  counter = 0;
  while (env_vars[counter])
    printf("%s\n", env_vars[counter++]);
  return (0);
}
