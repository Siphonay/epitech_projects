/*
** my_exit.c for my_exit in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr 11 19:27:27 2016 thibault derbre
** Last update Tue Apr 12 00:25:55 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	my_exit(t_data *data)
{
  int	i;
  int	f;

  data->if_exit = 1;
  i = 0;
  f = 0;
  while (data->full_cmd[i] != '\0')
    {
      if (data->full_cmd[i] >= '0' && data->full_cmd[i] <= '9')
	f = 1;
      i++;
    }
  i = 0;
  if (f == 0)
    return ;
  data->exit_id = my_getnbr(data->full_cmd);
}
