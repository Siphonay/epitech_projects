/*
** my_cd.c for my_cd in /home/zaza/rendu/PSU_2015_42sh/src/cd_builtin/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Tue May 31 21:00:51 2016 thibault derbre
** Last update Sun Jun  5 22:14:26 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

int	my_strcmp_setenv(char *str, char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '=')
    {
      if (buff[i] != str[i])
	return (0);
      i++;
    }
  return (1);
}

int     my_strcmp(char *s1, char *s2)
{
  while (*s1 == *s2++)
    {
      if (*s1++ == '\0')
	return (0);
    }
  return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

void	change_env_var_cd(int y, t_data *data, int f)
{
  char	*str;
  int	i;
  int	j;
  int	col;

  if (f == 1)
    str = data->pwd;
  else
    str = data->oldpwd;
  (1 ? i = 0,  j = strlen(str), free(data->env[y]) : 0);
  if ((data->env[y] = malloc((j + 8) * sizeof(char))) == NULL)
    return ;
  if (f == 1)
    {
      if ((data->env[y] = strcpy(data->env[y], "PWD=")) == NULL)
	return ;
    }
  else if ((data->env[y] = strcpy(data->env[y], "OLDPWD=")) == NULL)
    return ;
  while (data->env[y][i] != '=')
    i++;
  (1 ? i++, col = 0 : 0);
  while (str[col] != '\0')
    (1 ? data->env[y][i] = str[col], i++, col++ : 0);
  data->env[y][i] = '\0';
}

void	change_env_var(t_data *data)
{
  int	y;

  y = 0;
  while (data->env[y] != NULL)
    {
      if ((my_strcmp_setenv("PWD", data->env[y])) == 1)
	change_env_var_cd(y, data, 1);
      if ((my_strcmp_setenv("OLDPWD", data->env[y])) == 1)
	change_env_var_cd(y, data, 2);
      y++;
    }
}

int	my_cd(char **args, char **env, t_data *data)
{
  (void)env;
  data->args = args;
  if (data->args[1] == NULL)
    {
      if ((cd_home(data)) == -1)
	return (-1);
    }
  else if (data->args[2] != NULL)
    dprintf(STDERR_FILENO, "cd: Too many arguments.\n");
  else
    {
      my_change_directory(data);
    }
  return (0);
}
