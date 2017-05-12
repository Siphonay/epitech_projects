/*
** init_var.c for init_var in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Tue Apr  5 14:06:24 2016 thibault derbre
** Last update Mon Apr 11 19:38:35 2016 thibault derbre
*/

#include <unistd.h>
#include "mysh.h"

void	init_var(t_data *data)
{
  char	*buff;

  buff = NULL;
  data->nb_cmd = 0;
  data->if_exit = 0;
  data->exit_id = 0;
  data->pwd = getcwd(buff, 4096);
  data->oldpwd = getcwd(buff, 4096);
}
