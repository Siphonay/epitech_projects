/*
** cd_home.c for cd_home in /home/zaza/rendu/PSU_2015_42sh/src/cd_builtin/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed Jun  1 09:12:43 2016 thibault derbre
** Last update Sun Jun  5 20:12:44 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
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
	      data->tmp_pwd[*j] = data->env[*y][*i];
	      (*j)++;
	      (*i)++;
	    }
	  data->tmp_pwd[*j] = '\0';
	}
      (*y)++;
    }
}

int	take_var_len(t_data *data, char *str)
{
  int	y;
  int	i;
  int	j;

  y = 0;
  i = 0;
  j = 0;
  while (data->env[y] != NULL)
    {
      if ((my_strcmp_setenv(str, data->env[y])) == 1)
	{
	  while (data->env[y][i] != '=')
	    i++;
	  i++;
	  while (data->env[y][i] != '\0')
	    {
	      j++;
	      i++;
	    }
	  return (j);
	}
      y++;
    }
  return (-1);
}

int	change_data_var(t_data *data)
{
  char	*buff;
  int	y;
  int	i;
  int	j;

  (1 ? j = 0, i = 0, y = 0, buff = NULL : 0);
  if ((data->tmp_old = getcwd(buff, 4242)) == NULL)
    return (-1);
  if ((data->tmp_pwd = malloc((take_var_len(data, "HOME")
			       + 1 * sizeof(char)))) == NULL)
    return (-1);
  fill_data_var_cd(data, &i, &y, &j);
  if ((chdir(data->tmp_pwd)) == -1)
    {
      dprintf(STDERR_FILENO, "Problème lors du changement vers le home\n");
      return (-2);
    }
  return (0);
}

int	cd_home(t_data *data)
{
  int	f;

  if ((f = change_data_var(data)) == -1)
    return (-1);
  else if (f == -2)
    return (0);
  (1 ? free(data->pwd), free(data->oldpwd) : 0);
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
  (1 ? free(data->tmp_old), free(data->tmp_pwd) : 0);
  return (0);
  change_env_var(data);
  return (0);
}
