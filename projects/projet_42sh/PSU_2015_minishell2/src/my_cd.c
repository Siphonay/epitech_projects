/*
** my_cd.c for my_cd in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 12:27:38 2016 thibault derbre
** Last update Tue Apr 12 20:32:07 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	change_the_directory(t_data *data)
{
  if (data->args[1][0] == '/')
    {
      if ((change_begin_home(data)) == -1)
	return ;
    }
  else
    {
      if ((change_add_home(data)) == -1)
	return ;
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
    {
      change_the_directory(data);
    }
}

int	change_old_var(t_data *data)
{
  int	i;
  char	*buff;

  i = 0;
  buff = NULL;
  free(data->pwd);
  if ((data->pwd = malloc(my_strlen(data->oldpwd) + 1 * sizeof(char))) == NULL)
    exit(1);
  while (data->oldpwd[i] != '\0')
    {
      data->pwd[i] = data->oldpwd[i];
      i++;
    }
  data->pwd[i] = '\0';
  data->oldpwd = getcwd(buff, 4096);
  my_putstr(data->pwd);
  my_putchar('\n');
  if ((chdir(data->pwd)) == -1)
    return (-1);
  return (0);
}

void	old_directory(t_data *data)
{
  change_old_var(data);
  change_env_var(data);
}

void	my_cd(t_data *data)
{
  if (data->args[1] == NULL)
    {
      cd_home(data);
    }
  else if (data->args[2] != NULL)
    my_putstr("cd: Too many arguments.\n");
  else
    {
      my_change_directory(data);
    }
}
