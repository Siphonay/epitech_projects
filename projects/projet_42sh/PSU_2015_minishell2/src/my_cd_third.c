/*
** my_cd_third.c for my_cd in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr 11 18:10:19 2016 thibault derbre
** Last update Tue Apr 12 18:55:34 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

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
  return (0);
}

void	change_data_var(t_data *data)
{
  char	*buff;
  int	y;
  int	i;
  int	j;

  (1 ? j = 0, i = 0, y = 0, buff = NULL : 0);
  free(data->oldpwd);
  data->oldpwd = getcwd(buff, 4096);
  free(data->pwd);
  if ((data->pwd = malloc((take_var_len(data, "HOME")
			   + 1 * sizeof(char)))) == NULL)
    exit (1);
  fill_data_var_cd(data, &i, &y, &j);
  if ((chdir(data->pwd)) == -1)
    my_putstr("Problème lors du changement vers le home\n");
}

void	change_env_var_cd(int y, t_data *data, int f)
{
  char	*str;
  int	i;
  int	col;

  i = 0;
  if (f == 1)
    str = data->pwd;
  else
    str = data->oldpwd;
  if ((col = my_strlen(str) + 8) > data->max_col_env)
    realloc_table(data, col);
  while (data->env[y][i] != '=')
    i++;
  i++;
  col = 0;
  delete_value(data, y);
  while (str[col] != '\0')
    {
      data->env[y][i] = str[col];
      i++;
      col++;
    }
  data->env[y][i] = '\0';
}

void	change_env_var(t_data *data)
{
  int	y;
  int	f;

  y = 0;
  f = 0;
  while (data->env[y] != NULL)
    {
      if ((my_strcmp_setenv("PWD", data->env[y])) == 1)
	{
	  if (f == 2)
	    f = 3;
	  else
	    f = 1;
	  change_env_var_cd(y, data, 1);
	}
      if ((my_strcmp_setenv("OLDPWD", data->env[y])) == 1)
	{
	  if (f == 1)
	    f = 3;
	  else
	    f = 2;
	  change_env_var_cd(y, data, 2);
	}
      y++;
    }
}

void	cd_home(t_data *data)
{
  change_data_var(data);
  change_env_var(data);
}
