/*
** make_alias.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/conf_file/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Sat Jun  4 20:20:58 2016 Nolann Méléard
** Last update Sat Jun  4 23:16:58 2016 Nolann Méléard
*/

#include <unistd.h>
#include <string.h>
#include "mysh.h"

int	get_x(char **av, t_file *file, int x, int *len)
{
  int	i;
  int	y;
  int	c;

  i = 0;
  y = 0;
  c = 0;
  while (file[x].tab[i] != NULL)
    {
      if ((c = strlen(file[x].tab[i])) > *len)
	*len = c;
      i++;
    }
  while (av[y] != NULL)
    {
      if ((c = strlen(av[y])) > *len)
	*len = c;
      y++;
    }
  i = i + y;
  return (i);
}

char	**fill_cmd_alias(char **av, t_file *file, int x)
{
  char	**cmd;
  int	len;
  int	lines;
  int	i;

  len = 0;
  i = 0;
  lines = get_x(av, file, x, &len);
  if ((cmd = doublearray(lines, len + 1)) == NULL)
    return (NULL);
  while (file[x].tab[i] != NULL)
    {
      cmd[i] = strcpy(cmd[i], file[x].tab[i]);
      i++;
    }
  len = 1;
  while (av[len] != NULL)
    {
      cmd[i] = strcpy(cmd[i], av[len]);
      len++;
      i++;
    }
  cmd[i] = NULL;
  return (cmd);
}

char	**is_this_an_alias(char	**av, t_data *data)
{
  char	**cmd;
  int	c;
  int	i;

  i = 0;
  c = -1;
  while (c == -1 && data->file[i].param != NULL)
    {
      if ((strcmp(data->file[i].param, av[0])) == 0)
	c = i;
      i++;
    }
  if (c == -1)
    return (av);
  if ((cmd = fill_cmd_alias(av, data->file, c)) == NULL)
    return (av);
  i = 0;
  while (cmd[i] != NULL)
      i++;
  return (cmd);
}
