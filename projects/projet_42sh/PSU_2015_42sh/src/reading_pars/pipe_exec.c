/*
** pipe_exec.c for pipe_exec in /home/zaza/rendu/PSU_2015_42sh/src/reading_pars/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 22:18:06 2016 thibault derbre
** Last update Sun Jun  5 22:21:17 2016 thibault derbre
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "get_next_line.h"

int	exec_pipe(char **env, char **av, t_data *data, int fd[2])
{
  if (env == NULL)
    return (1);
  if (fd[0] != -2 && fd[0] != -1)
    dup2(fd[0], STDIN_FILENO);
  if (fd[1] != -2 && fd[1] != -1)
    dup2(fd[1], STDOUT_FILENO);
  if (fd[0] != -2 && fd[0] != -1)
    close(fd[0]);
  if (fd[1] != -2 && fd[1] != -1)
    close(fd[1]);
  data->env = get_exec(av, env, data);
  return (0);
}

int	replace_len(t_elem *elem, int *y, int *lines, int *max)
{
  int	len;

  len = strlen(elem->cmd[*y]);
  if (len > *max)
    *max = len;
  (*lines)++;
  (*y)--;
  return (0);
}

char	**calc_cmd_table_pipe(t_elem *elem, t_data *data, int *lines)
{
  int	y;
  int	max;
  int	tok;
  char	**cmd;

  (1 ? y = 0, max = 0 : 0);
  while (elem->cmd[y + 1] != NULL)
    y++;
  while (y != -1)
    {
      if (y != 0)
	{
	  tok = check_redirect(elem->cmd[y - 1]);
	  if ((tok == 1 || tok == 2) && data->is_out == 1)
	    return (NULL);
	  if ((tok == 3 || tok == 4) && data->is_in == 1)
	    return (NULL);
	  (tok != 0 ? y -= 2 : replace_len(elem, &y, lines, &max));
	}
      else
	replace_len(elem, &y, lines, &max);
    }
  if ((cmd = create_char_table(*lines + 2, max + 2)) == NULL)
    return (NULL);
  return (cmd);
}

void		prepare_pipe_exec(t_elem *elem, t_data *data)
{
  char		**cmd;
  int		lines;

  lines = 0;
  if ((cmd = calc_cmd_table_pipe(elem, data, &lines)) == NULL)
    exit(1);
  if ((cmd = fill_cmd_table(elem, cmd, lines)) == NULL)
    exit(1);
  execute_with_flow(elem, cmd, data, 1);
}

int		fill_flow(int fd[2], int pipes[2], t_data *data)
{
  setpgid(getpid(), getpid());
  if (pipes[0] != STDIN_FILENO)
    {
      data->is_in = 1;
      dup2(pipes[0], STDIN_FILENO);
      close(pipes[1]);
    }
  if (fd[1] != STDOUT_FILENO)
    {
      data->is_out = 1;
      dup2(fd[1], STDOUT_FILENO);
      close(fd[0]);
    }
  return (0);
}
