/*
** prepare_exec.c for prepare_exec in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 11:53:11 2016 thibault derbre
** Last update Sat Apr  9 14:01:40 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

char	*take_path_env(t_data *data)
{
  int	y;

  y = 0;
  while (data->env[y] != NULL)
    {
      if ((my_strcmp_env(data->env[y], "PATH=")) == 1)
	break;
      y++;
    }
  return (data->env[y]);
}

char	*pars_cmd(char *str)
{
  char	*src;
  int	len;
  int	i;

  i = 0;
  len = my_strlen(str);
  if ((src = malloc(len + 1 * sizeof(char))) == NULL)
    exit (1);
  while (str[i] != ' ')
    {
      src[i] = str[i];
      i++;
      if (str[i] == '\0')
	break;
    }
  src[i] = '\0';
  return (src);
}

int	check_path(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (0);
      i++;
    }
  return (1);
}

t_list	*fill_data_cmd(t_data *data, t_list *lex)
{
  data->args = lex->args;
  data->command = pars_cmd(lex->cmd);
  data->path = pars_cmd(lex->cmd);
  data->full_cmd = lex->cmd;
  data->path_pos = 5;
  data->end_instructions = 0;
  data->exc = -1;
  data->path_directories = take_path_env(data);
  data->if_path = check_path(data->command);
  return (lex);
}
