/*
** minishell1_execute.c for minishell1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 21:04:38 2016 Alexis Viguié
** Last update Wed Jan 27 23:28:43 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "sam.h"
#include "msh1.h"
#include "msh1_exec.h"

unsigned int	check_slash(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    {
      if (str[counter] == '/')
	return (1);
      counter++;
    }
  return (0);
}

int	exec_relative(char **argv, char **ep)
{
  pid_t	exec_pid;
  int	status;

  if (!access_file(argv[0]))
    {
      if ((exec_pid = fork()) == 0)
	{
	  execve(argv[0], argv, ep);
	  return (-1);
	}
      else if (exec_pid == -1)
	return (-1);
      else
	{
	  if (wait(&status) == -1)
	    return (-1);
	}
    }
  return (0);
}

int	execve_path(char *name, char **argv, char **ep)
{
  pid_t	exec_pid;
  int	status;

  if ((exec_pid = fork()) == 0)
    {
      execve(name, argv, ep);
      return (-1);
    }
  else if (exec_pid == -1)
    return (-1);
  else
    {
      if (wait(&status) == -1)
	return (-1);
    }
  return (0);
}

int		exec_path(char **argv, char **ep)
{
  char		**path_var;
  char		*arg_with_path;
  unsigned int	state;

  if ((path_var = sam_strtab(msh1_getenv(ep, PATH_ENAME), ":")) == NULL)
    return (-1);
  arg_with_path = NULL;
  state = msh1_get_exec_path(arg_with_path, argv[0], path_var);
  if (arg_with_path)
    {
      if (execve_path(arg_with_path, argv, ep) == -1)
	state = -1;
      free(arg_with_path);
    }
  else
    path_puterr(argv[0], state);
  sam_free_strtab(path_var);
  return (state);
}

int	msh1_exec_command(char **argv, char **ep)
{
  if (check_slash(argv[0]))
    {
      if (exec_relative(argv, ep) == -1)
	return (-1);
    }
  else
    {
      if (exec_path(argv, ep) == -1)
	return (-1);
    }
  return (0);
}
