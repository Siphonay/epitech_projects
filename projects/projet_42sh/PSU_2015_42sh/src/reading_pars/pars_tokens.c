/*
** pars_tokens.c for pars_tokens in /home/zaza/rendu/test/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 06:37:58 2016 thibault derbre
** Last update	Sun Jun 05 11:24:34 2016 pedron_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mysh.h"
#include "get_next_line.h"

int		prepare_exec(t_data *data, t_elem *elem)
{
  char		**cmd;
  int		lines;

  lines = 0;
  if ((cmd = calc_cmd_table(elem, &lines)) == NULL)
    return (-1);
  if ((cmd = fill_cmd_table(elem, cmd, lines)) == NULL)
    return (-1);
  execute_with_flow(elem, cmd, data, 0);
  return (0);
}

int		check_pipes(t_elem *elem,  t_data *data)
{
  int		pipes[2];

  if (data->nb_pipe == 0)
    {
      elem->cmd = is_this_an_alias(elem->cmd, data);
      if ((strcmp("exit", elem->cmd[0]) == 0))
	{
	  exit_builtin(elem, elem->cmd, data->env, data);
	  dprintf(STDERR_FILENO, "exit: Expression Syntax.\n");
	  elem = elem->next;
	}
      else
	prepare_exec(data, elem);
      return (0);
    }
  data->is_piped = 0;
  pipes[0] = STDIN_FILENO;
  pipes[1] = -1;
  if ((function_pipe(elem, data, pipes)) == -1)
    return (-1);
  return (0);
}

int		go_other(t_elem *elem, t_data *data)
{
  t_elem	*tmp;
  int		pipes;

  (1 ? tmp = elem, pipes = 0 : 0);
  while (elem)
    {
      if (elem->id == ISOR || elem->id == ISAND || elem->id == COL)
	{
	  data->nb_pipe = pipes;
	  check_pipes(tmp, data);
          if (elem->id == ISOR && data->exec == 0)
            return (0);
          else if (elem->id == ISAND && data->exec != 0)
            return (0);
	  (1 ? pipes = 0, elem = elem->next, tmp = elem : 0);
	}
      else if (elem->id == SPIPE)
	pipes++;
      elem = elem->next;
    }
  data->nb_pipe = pipes;
  check_pipes(tmp, data);
  return (0);
}

void		go_pars(t_list list, t_data *data)
{
  int		pipe;
  t_elem	*elem;
  t_elem	*tmp;

  pipe = 0;
  elem = list.first;
  while (elem)
    {
      if (elem->id == ISOR || elem->id == ISAND || elem->id == COL)
	break;
      else if (elem->id == SPIPE)
	pipe++;
      elem = elem->next;
    }
  tmp = list.first;
  data->nb_pipe = pipe;
  check_pipes(tmp, data);
  if (elem == NULL)
    return ;
  if (elem->id == ISOR && data->exec == 0)
    return ;
  else if (elem->id == ISAND && data->exec != 0)
    return ;
  elem = elem->next;
  go_other(elem, data);
}

t_list		pars_token(t_list list, t_data *data)
{
  data->fail = 0;
  data->exec = 0;
  data->is_in = 0;
  data->is_out = 0;
  if ((check_tokens(list)) != 0)
    return (list);
  if ((check_flow_command(list)) != 0)
    return (list);
  go_pars(list, data);
  return (list);
}
