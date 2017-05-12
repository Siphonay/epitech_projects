/*
** minishell1_exec_aux.c for minishell1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 21:56:39 2016 Alexis Viguié
** Last update Wed Jan 27 23:36:27 2016 Alexis Viguié
*/

#include <unistd.h>
#include "sam.h"
#include "msh1.h"

void	exec_puterr(char *name, char *err)
{
  sam_putstr_err(name);
  sam_putstr_err(err);
}

void	path_puterr(char *name, int err)
{
  sam_putstr_err(name);
  if (err == 2)
    sam_putstr_err(EXEC_NOEXEC);
  else
    sam_putstr_err(EXEC_NOTFOUND);
}

int	access_file(char *name)
{
  if (access(name, F_OK) == -1)
    {
      exec_puterr(name, EXEC_NOTFOUND);
      return (1);
    }
  else if (access(name, F_OK == -1))
    {
      exec_puterr(name, EXEC_NOEXEC);
      return (1);
    }
  return (0);
}

unsigned int	access_file_path(char *name)
{
  if (access(name, F_OK) == -1)
    return (1);
  else if (access(name, X_OK) == -1)
    return (2);
  else
    return (0);
}

int	exec_path_free_exit(char **path_var)
{
  sam_free_strtab(path_var);
  return (-1);
}
