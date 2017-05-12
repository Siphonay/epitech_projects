/*
** my_cd_bis.c for my_cd in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr 11 18:10:14 2016 thibault derbre
** Last update Tue Apr 12 20:34:09 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	fill_data_var_cd(t_data *data, int *i, int *y, int *j)
{
  while (data->env[*y] != NULL)
    {
      if ((my_strcmp_setenv("HOME", data->env[*y])) == 1)
	{
	  while (data->env[*y][*i] != '=')
	    (*i)++;
	  (*i)++;
	  while (data->env[*y][*i] != '\0')
	    {
	      data->pwd[*j] = data->env[*y][*i];
	      (*j)++;
	      (*i)++;
	    }
	  data->pwd[*j] = '\0';
	}
      (*y)++;
    }
}

int	change_data_remote(t_data *data)
{
  int	i;
  char	*buff;

  (1 ? i = 0, buff = NULL : 0);
  if ((data->oldpwd = getcwd(buff, 4096)) == NULL)
    return (-1);
  free(data->pwd);
  if ((data->pwd = malloc((my_strlen(data->oldpwd) * sizeof(char)))) == NULL)
    exit (1);
  while (data->oldpwd[i + 1] != '\0')
    i++;
  while (data->oldpwd[i] != '/')
    i--;
  data->pwd[i] = '\0';
  i--;
  while (i != -1)
    {
      data->pwd[i] = data->oldpwd[i];
      i--;
    }
  ((my_strlen(data->pwd) == 0) ? data->pwd[0] = '/', data->pwd[1] = '\0' : 0);
  if ((chdir(data->pwd)) == -1)
    return (-1);
  return (0);
}

void	remote_cd_directory(t_data *data)
{
  if ((my_strcmp(data->pwd, "/")) == 0)
    return ;
  if ((change_data_remote(data)) == -1)
    return ;
  change_env_var(data);
}

int	change_begin_home(t_data *data)
{
  char	*buff;
  char	*str;
  int	i;

  buff = NULL;
  i = 0;
  if ((str = malloc((my_strlen(data->args[1]) + 1 * sizeof(char)))) == NULL)
    exit(1);
  while (data->args[1][i] != '\0')
    {
      str[i] = data->args[1][i];
      i++;
    }
  str[i] = '\0';
  if ((chdir(str)) == -1)
    {
      my_putstr(str);
      my_putstr(": Aucun fichier ou dossier de ce type.\n");
      return (-1);
    }
  free(data->oldpwd);
  data->oldpwd = getcwd(buff, 4096);
  free(data->pwd);
  data->pwd = str;
  return (0);
}

int	change_add_home(t_data *data)
{
  char	*str;
  char	*buff;
  int	i;

  buff = NULL;
  i = 0;
  while (data->args[1][i] != '\0')
    i++;
  if (data->args[1][i - 1] == '/')
    data->args[1][i - 1] = '\0';
  str = my_strcat_cd(data->args[1], data->pwd);
  free(data->oldpwd);
  data->oldpwd = getcwd(buff, 4096);
  if ((chdir(str)) == -1)
    {
      my_putstr(str);
      my_putstr(": Aucun fichier ou dossier de ce type.\n");
      return (-1);
    }
  free(data->pwd);
  data->pwd = str;
  return (0);
}
