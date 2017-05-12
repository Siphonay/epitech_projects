/*
** check_flow.c for check_flow in /home/zaza/rendu/PSU_2015_42sh/src/reading_pars/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 22:13:19 2016 thibault derbre
** Last update Sun Jun  5 22:28:37 2016 thibault derbre
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "get_next_line.h"

int		check_str_flow(char *str)
{
  int		i;
  int		r;
  int		l;

  i = 0;
  l = 0;
  r = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '>')
	r = 1;
      else if (str[i] == '<')
	l = 1;
      i++;
    }
  if (l == 1 && r == 1)
    return (-1);
  else if (l == 1)
    return (1);
  else if (r == 1)
    return (2);
  return (0);
}

int		check_command_flow(int *f, int fd[2], char **cmd, int y)
{
  if ((*f = check_str_flow(cmd[y])) != 0)
    {
      if (*f == -1)
	return (-1);
      else if (*f == 1)
	{
	  if (fd[0] == 1)
	    return (-1);
	  fd[0] = 1;
	}
      else if (*f == 2)
	{
	  if (fd[1] == 1)
	    return (-1);
	  fd[1] = 1;
	}
    }
  return (0);
}

int		check_flow_table(char **cmd)
{
  int	y;
  int	fd[2];
  int	f;

  (1 ? y = 0, fd[0] = 0, fd[1] = 0 : 0);
  while (cmd[y] != NULL)
    {
      if ((check_command_flow(&f, fd, cmd, y)) == -1)
	return (-1);
      y++;
    }
  return (0);
}

int		check_flow_command(t_list list)
{
  t_elem	*elem;

  elem = list.first;
  while (elem)
    {
      if (elem->id != SPIPE && elem->id != ISOR && elem->id
	  != ISAND && elem->id != COL)
	{
	  if ((check_flow_table(elem->cmd)) == -1)
	    return (2);
	}
      elem = elem->next;
    }
  return (0);
}

int	error_redirect(void)
{
  dprintf(STDERR_FILENO, "Missing name for redirect.\n");
  return (-1);
}
