/*
** main.c for main in /home/zaza/rendu/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr 18 13:35:05 2016 thibault derbre
** Last update	Sat Jun 04 22:27:37 2016 pedron_s
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mysh.h"

char	**init_env()
{
  char	**env;

  env = doublearray(1, 20);
  env[0] = strcpy(env[0], "PATH=/usr/bin");
  return (env);
}

int	main(int argc, char **argv, char **env)
{
  t_data	*data;

  (void)argc;
  (void)argv;
  init_signal();
  if ((data = malloc(sizeof(t_data))) == NULL)
    return (EXIT_FAILURE);
  if (env[0] != NULL)
    data->env = get_env(env);
  else
    data->env = init_env();
  data = get_file(data);
  if ((data = launch_commands(data)) == NULL)
    return (EXIT_FAILURE);
  dprintf(STDOUT_FILENO, "exit\n");
  return (EXIT_SUCCESS);
}
