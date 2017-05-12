/*
** pipe.c for pipe in /home/zaza/rendu/test/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 06:38:39 2016 thibault derbre
** Last update	Sun Jun 05 11:29:56 2016 pedron_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "get_next_line.h"

int	choice_pipe(t_elem *elem, t_data *data)
{
  elem->cmd = is_this_an_alias(elem->cmd, data);
  prepare_pipe_exec(elem, data);
  return (0);
}

int	end_execute_pipe(pid_t pid, int pipes[2], int fd[2])
{
  int	status;

  tcsetpgrp(STDIN_FILENO, pid);
  waitpid(pid, &status, 0);
  tcsetpgrp(STDIN_FILENO, getpgid(getpid()));
  if (status >= 128 && status <= 139)
    dprintf(STDERR_FILENO, "Segmentation fault (core dumped)\n");
  if (pipes[0] != STDIN_FILENO)
    {
      if ((close(pipes[0])) == -1)
	return (-1);
    }
  if (fd[1] != STDOUT_FILENO)
    {
      if ((close(fd[1])) == -1)
	return (-1);
    }
  return (0);
}

int		init_pipes(t_data *data, int fd[2])
{
  data->is_in = 0;
  data->is_out = 0;
  if (data->is_piped == data->nb_pipe)
    fd[1] = STDOUT_FILENO;
  else
    {
      if ((pipe(fd)) == -1)
	return (-1);
    }
  return (0);
}

int		function_pipe(t_elem *elem, t_data *data, int pipes[2])
{
  pid_t		pid;
  int		fd[2];

  init_pipes(data, fd);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      fill_flow(fd, pipes, data);
      choice_pipe(elem, data);
    }
  else
    {
      end_execute_pipe(pid, pipes, fd);
      elem = elem->next;
      if (elem == NULL)
	return (0);
      if (elem->id == SPIPE)
	elem = elem->next;
      if (data->is_piped == data->nb_pipe)
	return (2);
      data->is_piped++;
      function_pipe(elem, data, fd);
    }
  return (0);
}
