/*
** minishell1_exec_getpath.c for minishell1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 22:57:46 2016 Alexis Viguié
** Last update Wed Jan 27 23:19:58 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"
#include "msh1_exec.h"

int		msh1_get_exec_path(char *arg_with_path, char *name, char **path_var)
{
  unsigned int	last_state;
  unsigned int	was_found_without_exec;
  unsigned int	counter;

  last_state = 0;
  counter = 0;
  was_found_without_exec = 1;
  while (path_var[counter] && arg_with_path == NULL)
    {
      if ((arg_with_path =
	   sam_strncat(path_var[counter], name, sam_strlen(name))) == NULL)
	return (exec_path_free_exit(path_var));
      if ((last_state = access_file_path(name)))
	{
	  if (last_state == 2)
	    was_found_without_exec = 1;
	  free(arg_with_path);
	  arg_with_path = NULL;
	}
      counter++;
    }
  if (was_found_without_exec && !arg_with_path)
    return (2);
  else
    return (!arg_with_path);
}
