/*
** env.c for env in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 12:27:52 2016 thibault derbre
** Last update Mon Apr 11 10:43:49 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	my_env(t_data *data)
{
  int	y;

  y = 0;
  while (data->env[y] != NULL)
    {
      my_putstr(data->env[y]);
      my_putchar('\n');
      y++;
    }
}
