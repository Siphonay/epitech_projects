/*
** change_directory.c for change_directory in /home/zaza/rendu/PSU_2015_42sh/src/cd_builtin/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed Jun  1 09:14:08 2016 thibault derbre
** Last update Sun Jun  5 20:11:56 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

char	*my_strcat_cd(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  (1 ? j = strlen(dest), i = strlen(src) : 0);
  if ((str = malloc((i + j) + 2 * sizeof(char))) == NULL)
    return (NULL);
  (1 ? j = 0, i = 0 : 0);
  while (src[i] != '\0')
    (1 ? str[j] = src[i], i++, j++ : 0);
  str[j] = '/';
  j++;
  i = 0;
  while (dest[i] != '\0')
    {
      str[j] = dest[i];
      i++;
      j++;
    }
  str[j] = '\0';
  return (str);
}

int	change_add_home(t_data *data)
{
  char	*buff;
  int	i;

  i = 0;
  buff = NULL;
  while (data->args[1][i] != '\0')
    i++;
  if (data->args[1][i - 1] == '/')
    data->args[1][i - 1] = '\0';
  if ((data->tmp_pwd = my_strcat_cd(data->args[1], data->pwd)) == NULL)
    return (-1);
  if ((data->tmp_old = getcwd(buff, 4096)) == NULL)
    return (-1);
  if ((chdir(data->tmp_pwd)) == -1)
    {
      dprintf(STDERR_FILENO, "%s%s\n", data->tmp_pwd,
	      ": Aucun fichier ou dossier de ce type.\n");
      return (-1);
    }
  return (0);
}

int	change_begin_home(t_data *data)
{
  char	*buff;
  int	i;

  (1 ? buff = NULL, i = 0 : 0);
  if ((data->tmp_old = getcwd(buff, 4096)) == NULL)
    return (-1);
  if ((data->tmp_pwd = malloc((strlen(data->args[1])
			       + 1 * sizeof(char)))) == NULL)
    return (-1);
  while (data->args[1][i] != '\0')
    (1 ? data->tmp_pwd[i] = data->args[1][i], i++ : 0);
  data->tmp_pwd[i] = '\0';
  if ((chdir(data->tmp_pwd)) == -1)
    return (-2);
  (1 ? free(data->pwd), free(data->oldpwd) : 0);
  if ((data->pwd = malloc(((strlen(data->tmp_pwd)) + 1) * sizeof(char)))
      == NULL || (data->oldpwd = malloc(((strlen(data->tmp_old)) + 1)
					* sizeof(char))) == NULL)
    return (-1);
  if ((data->pwd = strcpy(data->pwd, data->tmp_pwd)) == NULL)
    return (-1);
  if ((data->oldpwd = strcpy(data->oldpwd, data->tmp_old)) == NULL)
    return (-1);
  return (0);
}

void	change_the_directory(t_data *data)
{
  if (data->args[1][0] == '/')
    {
      if ((change_begin_home(data)) != 0)
	return ;
      (1 ? free(data->tmp_old), free(data->tmp_pwd) : 0);
    }
  else
    {
      if ((change_add_home(data)) != 0)
	return ;
      (1 ? free(data->pwd), free(data->oldpwd) : 0);
      if ((data->pwd = malloc(((strlen(data->tmp_pwd)) + 1) *
			      sizeof(char))) == NULL)
	return ;
      if ((data->pwd = strcpy(data->pwd, data->tmp_pwd)) == NULL)
	return ;
      if ((data->oldpwd = malloc(((strlen(data->tmp_old)) + 1) *
				 sizeof(char))) == NULL)
	return ;
      if ((data->oldpwd = strcpy(data->oldpwd, data->tmp_old)) == NULL)
	return ;
      (1 ? free(data->tmp_old), free(data->tmp_pwd) : 0);
    }
  change_env_var(data);
}

void	my_change_directory(t_data *data)
{
  if ((my_strcmp(data->args[1], "..")) == 0)
    remote_cd_directory(data);
  else if ((my_strcmp(data->args[1], "-")) == 0)
    old_directory(data);
  else
    change_the_directory(data);
}
