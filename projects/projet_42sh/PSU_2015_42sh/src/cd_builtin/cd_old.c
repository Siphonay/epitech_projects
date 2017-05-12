/*
** cd_old.c for cd_old in /home/zaza/rendu/PSU_2015_42sh/src/cd_builtin/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed Jun  1 09:13:56 2016 thibault derbre
** Last update Sun Jun  5 20:12:25 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

int	change_old_var(t_data *data)
{
  int	i;
  char	*buff;

  i = 0;
  buff = NULL;
  if ((data->tmp_pwd = malloc(strlen(data->oldpwd) + 1
			      * sizeof(char))) == NULL)
    return (-1);
  while (data->oldpwd[i] != '\0')
    {
      data->tmp_pwd[i] = data->oldpwd[i];
      i++;
    }
  data->tmp_pwd[i] = '\0';
  if ((data->tmp_old = getcwd(buff, 4096)) == NULL)
    return (-1);
  if ((chdir(data->tmp_pwd)) == -1)
    return (-2);
  dprintf(STDOUT_FILENO, "%s\n", data->tmp_pwd);
  return (0);
}

void	old_directory(t_data *data)
{
  if ((change_old_var(data)) != 0)
    return ;
  free(data->pwd);
  free(data->oldpwd);
  if ((data->pwd = malloc(((strlen(data->tmp_pwd)) + 1) * sizeof(char)))
      == NULL)
    return ;
  if ((data->pwd = strcpy(data->pwd, data->tmp_pwd)) == NULL)
    return ;
  if ((data->oldpwd = malloc(((strlen(data->tmp_old)) + 1) * sizeof(char)))
      == NULL)
    return ;
  if ((data->oldpwd = strcpy(data->oldpwd, data->tmp_old)) == NULL)
    return ;
  free(data->tmp_old);
  free(data->tmp_pwd);
  change_env_var(data);
}
