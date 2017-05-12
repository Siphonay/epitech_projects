/*
** execution.c for execution in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 11:52:07 2016 thibault derbre
** Last update Tue Apr 12 18:39:20 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "mysh.h"

char	*fill_src(char *src, t_data *data)
{
  int	len;
  int	tmp;

  len = 0;
  tmp = 0;
  while (data->path_directories[data->path_pos] != ':'
	 && data->path_directories[data->path_pos] != '\0')
    {
      src[len] = data->path_directories[data->path_pos];
      len++;
      data->path_pos++;
    }
  src[len] = '/';
  len++;
  while (data->command[tmp] != '\0')
    {
      src[len] = data->command[tmp];
      len++;
      tmp++;
    }
  src[len] = '\0';
  return (src);
}

char	*binary_directories(t_data *data)
{
  int	tmp;
  int	len;
  char	*src;
  int	max;

  len = 0;
  tmp = data->path_pos;
  while (data->path_directories[tmp] != ':'
	 && data->path_directories[tmp] != '\0')
    {
      tmp++;
      len++;
    }
  max = (my_strlen(data->command)) + (len + 2);
  if ((src = malloc(max * sizeof(char))) == NULL)
    exit (1);
  src = fill_src(src, data);
  if (data->path_directories[data->path_pos] == '\0')
    data->end_instructions = 1;
  data->path_pos++;
  return (src);
}

void	execution(t_data *data)
{
  if (data->if_path == 0)
    {
      if ((data->exc = execve(data->path, data->args, data->env)) == -1)
	data->end_instructions = 1;
    }
  if (data->if_path == 1)
    {
      while (data->exc == -1)
	{
	  data->path = binary_directories(data);
	  data->exc = execve(data->path, data->args, data->env);
	  if (data->end_instructions == 1)
	    break;
	}
    }
  if (data->exc == -1 && data->end_instructions == 1)
    {
      show_error(data);
      exit (0);
    }
}

void	exec_cmd(t_data *data)
{
  pid_t pid;
  int	super_segfault;

  super_segfault = 0;
  if ((builtins(data)) == 0)
    return ;
  pid = fork();
  if (pid == 0)
    {
      execution(data);
      return ;
    }
  else
    wait(&super_segfault);
  if (super_segfault == 139)
    my_putstr("Segmentation fault (core dumped)\n");
}

void	launch_commands(t_data *data, t_list *lex)
{
  while (lex->next != NULL)
    {
      if (lex->id == 0)
	{
	  lex = fill_data_cmd(data, lex);
	  exec_cmd(data);
	}
      lex = lex->next;
    }
  if (lex->id == 0)
    {
      lex = fill_data_cmd(data, lex);
      exec_cmd(data);
    }
}
