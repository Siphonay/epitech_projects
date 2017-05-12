/*
** remote_cd_directory.c for remote_cd_directory in /home/zaza/rendu/PSU_2015_42sh/src/cd_builtin/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed Jun  1 09:13:25 2016 thibault derbre
** Last update Sun Jun  5 20:06:46 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

int	change_data_remote(t_data *data)
{
  int	i;
  char	*buff;

  (1 ? i = 0, buff = NULL : 0);
  if ((data->tmp_old = getcwd(buff, 4096)) == NULL)
    return (-1);
  if ((data->tmp_pwd = malloc((strlen(data->tmp_old) *
			       sizeof(char)))) == NULL)
    return (-1);
  while (data->tmp_old[i + 1] != '\0')
    i++;
  while (data->tmp_old[i] != '/')
    i--;
  data->tmp_pwd[i] = '\0';
  i--;
  while (i != -1)
    {
      data->tmp_pwd[i] = data->tmp_old[i];
      i--;
    }
  ((strlen(data->tmp_pwd) == 0) ? data->tmp_pwd[0] = '/',
   data->tmp_pwd[1] = '\0' : 0);
  if ((chdir(data->tmp_pwd)) == -1)
    return (-2);
  return (0);
}

int	remote_cd_directory(t_data *data)
{
  int	f;

  if ((my_strcmp(data->pwd, "/")) == 0)
    return (0);
  if ((f = change_data_remote(data)) == -1)
    return (-1);
  else if (f == -2)
    return (-2);
  free(data->pwd);
  free(data->oldpwd);
  if ((data->pwd = malloc(((strlen(data->tmp_pwd)) + 1) * sizeof(char)))
      == NULL)
    return (-1);
  if ((data->pwd = strcpy(data->pwd, data->tmp_pwd)) == NULL)
    return (-1);
  if ((data->oldpwd = malloc(((strlen(data->tmp_old)) + 1) * sizeof(char)))
      == NULL)
    return (-1);
  if ((data->oldpwd = strcpy(data->oldpwd, data->tmp_old)) == NULL)
    return (-1);
  free(data->tmp_old);
  free(data->tmp_pwd);
  change_env_var(data);
  return (0);
}
