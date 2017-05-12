/*
** command.c for command in /home/zaza/rendu/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed May 11 17:53:32 2016 thibault derbre
** Last update	Sun Jun 05 18:02:34 2016 pedron_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mysh.h"
#include "get_next_line.h"

char	*show_prompt(void)
{
  char	*s;

  my_putstr("\033[1;34m[42sh] -> \033[0m");
  if ((s = get_next_line(STDIN_FILENO)) == NULL)
    return (NULL);
  return (s);
}

void	show_table(char **table)
{
  int	y;

  y = 0;
  while (table[y] != NULL)
    {
      printf("%s\n", table[y]);
      y++;
    }
}

t_data	*set_var(t_data *data)
{
  char	*buff;
  char	*str;

  buff = NULL;
  if ((str = getcwd(buff, 4096)) == NULL)
    return (NULL);
  if ((data->pwd = malloc(((strlen(str) + 1)) * sizeof(char))) == NULL)
    return (NULL);
  if ((data->pwd = strcpy(data->pwd, str)) == NULL)
    return (NULL);
  if ((str = getcwd(buff, 4096)) == NULL)
    return (NULL);
  if ((data->oldpwd = malloc(((strlen(str) + 1)) * sizeof(char))) == NULL)
    return (NULL);
  if ((data->oldpwd = strcpy(data->oldpwd, str)) == NULL)
    return (NULL);
  return (data);
}

t_data	*launch_commands(t_data *data)
{
  char		*s;
  t_list	list;

  if ((set_var(data)) == NULL)
    return (NULL);
  while (42)
    {
      if ((s = show_prompt()) == NULL)
	return (data);
      list = init_list(data, s);
      if (list.check == 0)
	pars_token(list, data);
    }
  return (data);
}
