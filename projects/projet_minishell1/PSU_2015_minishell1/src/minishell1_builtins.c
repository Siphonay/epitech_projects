/*
** minishell1_builtins.c for minishell1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 11:38:25 2016 Alexis Viguié
** Last update Wed Jan 27 20:59:05 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sam.h"
#include "msh1.h"

void	builtin_exit(char **input, char **ep, char *arg)
{
  char	exit_value;

  if (arg)
    exit_value = sam_get_nbr(arg);
  else
    exit_value = 0;
  sam_free_strtab(input);
  sam_free_strtab(ep);
  exit(exit_value);
}

void	cd_errdisp(char *dir_name, char *error)
{
  sam_putstr_err(dir_name);
  sam_putstr_err(error);
}

void	builtin_cd(char *dir_name)
{
  DIR	*destdir;
  int	filetest;

  if (dir_name)
    {
      if ((destdir = opendir(dir_name)))
	{
	  if (closedir(destdir))
	    cd_errdisp(dir_name, CD_ERR_ACCESS);
	  else if (chdir(dir_name))
	    cd_errdisp(dir_name, CD_ERR_ACCESS);
	}
      else if ((filetest = open(dir_name, O_WRONLY)) != -1)
	{
	  close(filetest);
	  cd_errdisp(dir_name, CD_ERR_NOTAFOLDER);
	}
      else
	cd_errdisp(dir_name, CD_ERR_NOTFOUND);
    }
  else
    sam_putstr_err(CD_USAGE);
}

int	msh1_builtins(char **input, char **ep)
{
  if (!sam_strcmp(input[0], MSH1_BUILTIN_EXIT))
    builtin_exit(input, ep, input[1]);
  else if (!sam_strcmp(input[0], MSH1_BUILTIN_CD))
    builtin_cd(input[1]);
  else if (!sam_strcmp(input[0], MSH1_BUILTIN_SETENV))
    {
      if (msh1_env_builtin_set(input, ep) == -1)
	return (-1);
    }
  else if (!sam_strcmp(input[0], MSH1_BUILTIN_UNSETENV))
    {
      if (msh1_env_builtin_unset(input, ep) == -1)
	return (-1);
    }
  else if (!sam_strcmp(input[0], MSH1_BUILTIN_ENV))
    msh1_env_builtin_disp(ep);
  else
    return (0);
  return (1);
}
