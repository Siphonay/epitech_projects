/*
** check_tokens.c for check_tokens in /home/zaza/rendu/PSU_2015_42sh/src/reading_pars/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 22:13:32 2016 thibault derbre
** Last update Sun Jun  5 22:28:46 2016 thibault derbre
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "get_next_line.h"

int	check_id(t_elem *elem)
{
  if (elem->id == SPIPE || elem->id == ISOR
      || elem->id == ISAND || elem->id == COL)
    return (1);
  return (0);
}

int		check_redirect(char *str)
{
  if (((strcmp(str, ">>")) == 0)
      || ((strcmp(str, ">")) == 0)
      || ((strcmp(str, "<")) == 0)
      || ((strcmp(str, "<<")) == 0))
    return (1);
  return (0);
}

int		error_binary(void)
{
  dprintf(STDERR_FILENO, "Invalid null command.\n");
  return (2);
}

int		check_tokens(t_list list)
{
  t_elem	*elem;

  elem = list.first;
  if (elem->id == SPIPE || elem->id == ISOR)
    return ((error_binary()));
  else if (elem->id == COL)
    return (1);
  while (elem)
    {
      if (elem->id == SPIPE || elem->id == ISOR || elem->id == ISAND)
	{
	  if (elem->next == NULL)
	    return ((error_binary()));
	  else if ((check_id(elem->next)) == 1)
	    return ((error_binary()));
	}
      elem = elem->next;
    }
  return (0);
}
