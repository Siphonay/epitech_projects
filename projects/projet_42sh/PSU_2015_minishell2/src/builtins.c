/*
** builtins.c for buitins in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 04:03:13 2016 thibault derbre
** Last update Mon Apr 11 21:05:05 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "mysh.h"

int	builtins(t_data *data)
{
  int	f;

  f = 1;
  if ((f = my_strcmp(data->command, "setenv")) == 0)
    my_set_env(data);
  else if ((f = my_strcmp(data->command, "env")) == 0)
    my_env(data);
  else if ((f = my_strcmp(data->command, "unsetenv")) == 0)
    my_unsetenv(data);
  else if ((f = my_strcmp(data->command, "cd")) == 0)
    my_cd(data);
  else if ((f = my_strncmp(data->command, "exit", 4)) == 0)
    my_exit(data);
  return (f);
}
