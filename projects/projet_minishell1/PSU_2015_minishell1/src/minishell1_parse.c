/*
** minishell1_parse.c for minishell1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Jan 19 19:58:22 2016 Alexis Viguié
** Last update Wed Jan 27 17:58:41 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"
#include "msh1.h"

int	msh1_parse_input(char *input, char **ep)
{
  char	**input_argv;
  int	is_builtin;

  if ((input_argv = sam_strtab(input, " \t")) == NULL)
    return (0);
  if ((is_builtin = msh1_builtins(input_argv, ep)) == -1)
    {
      sam_free_strtab(input_argv);
      return (-1);
    }
  if (!is_builtin)
    {
      if (msh1_exec_command(input_argv, ep) == -1)
	{
	  sam_free_strtab(input_argv);
	  return (-1);
	}
    }
  sam_free_strtab(input_argv);
  return (0);
}
