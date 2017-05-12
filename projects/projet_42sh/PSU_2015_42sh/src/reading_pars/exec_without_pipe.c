/*
** exec_without_pipe.c for exec_without_pipe in /home/zaza/rendu/PSU_2015_42sh/src/reading_pars/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 22:19:09 2016 thibault derbre
** Last update Sun Jun  5 22:21:20 2016 thibault derbre
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "get_next_line.h"

int	calc_var_tables(t_elem *elem, int *lines, int *y, int *max)
{
  int	len;

  if (*y != 0)
    {
      if ((check_redirect(elem->cmd[*y - 1])) == 1)
        *y -= 2;
      else
        {
          len = strlen(elem->cmd[*y]);
          if (len > *max)
            *max = len;
          (*lines)++;
          (*y)--;
        }
    }
  else
    {
      len = strlen(elem->cmd[*y]);
      if (len > *max)
	*max = len;
      (*lines)++;
      (*y)--;
    }
  return (0);
}

char	**calc_cmd_table(t_elem *elem, int *lines)
{
  int	y;
  int	max;
  char	**cmd;

  y = 0;
  max = 0;
  while (elem->cmd[y] != NULL)
    y++;
  y--;
  while (y != -1)
    calc_var_tables(elem, lines, &y, &max);
  if ((cmd = create_char_table(*lines + 2, max + 2)) == NULL)
    return (NULL);
  return (cmd);
}

char	**copy_command(t_elem *elem, char **cmd, int *y, int *lines)
{
  if (*y != 0)
    {
      if ((check_redirect(elem->cmd[*y - 1])) == 1)
	*y -= 2;
      else
	{
	  cmd[*lines] = strcpy(cmd[*lines], elem->cmd[*y]);
	  (*lines)--;
	  (*y)--;
	}
    }
  else
    {
      cmd[*lines] = strcpy(cmd[*lines], elem->cmd[*y]);
      (*lines)--;
      (*y)--;
    }
  return (cmd);
}

char	**fill_cmd_table(t_elem *elem, char **cmd, int lines)
{
  int	y;

  y = 0;
  cmd[lines] = NULL;
  lines--;
  while (elem->cmd[y] != NULL)
    y++;
  y--;
  while (y != -1)
    cmd = copy_command(elem, cmd, &y, &lines);
  return (cmd);
}

int	check_flow(char *str)
{
  if ((my_strcmp(str, ">")) == 0)
    return (1);
  if ((my_strcmp(str, ">>")) == 0)
    return (2);
  if ((my_strcmp(str, "<")) == 0)
    return (3);
  if ((my_strcmp(str, "<<")) == 0)
    return (4);
  return (0);
}
