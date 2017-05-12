/*
** export.c for 42 in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/conf_file/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Fri Jun  3 13:40:33 2016 Nolann Méléard
** Last update Sun Jun  5 11:32:16 2016 Nolann Méléard
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "mysh.h"

int	charisalphanum(char s, char sep1, char sep2)
{
  int	i;

  i = -1;
  if (s >= 'A' && s <= 'Z')
    i = 0;
  if (s >= 'a' && s <= 'z')
    i = 0;
  if (s >= '0' && s <= '9')
    i = 0;
  if (s == sep1)
    i = 1;
  if (s == sep2)
    i = 1;
  return (i);
}

int	verif_export(char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  i++;
  if (str[i] == '\0' || (charisalphanum(str[i], 'A', 'A')) == -1)
    return (-1);
  while (str[i] != '=' && str[i] != '\0')
    {
      if ((charisalphanum(str[i], '_', 'A')) == -1)
	return (-1);
      i++;
    }
  if (str[i] == '\0')
    return (-1);
  i++;
  if ((charisalphanum(str[i], '"', 39)) != 1)
    return (-1);
  i++;
  while (str[i] != '"' &&  str[i] != 39 && str[i] != '\0')
    i++;
  if (str[i] == '\0' || str[i + 1] != '\0')
    return (-1);
  return (0);
}

char	**get_cmd(char *str)
{
  char	**cmd;
  int	i;
  int	j;

  i = 0, j = 0;
  if ((verif_export(str)) == -1)
    return (NULL);
  if ((cmd = doublearray(3, strlen(str))) == NULL)
    return (NULL);
  while (str[i] != ' ' && str[i] != '\0')
    i++;
  i++;
  cmd[0] = strcpy(cmd[0], "setenv");
  while (str[i] != '=')
    cmd[1][j++] = str[i++];
  j = 0, i += 2;
  while (str[i] != '\0')
    cmd[2][j++] = str[i++];
  cmd[2][j - 1] = '\0';
  return (cmd);
}

int	export(char **file, t_data *data)
{
  int	i;
  char	**cmd;

  i = 0;
  while (file[i] != NULL)
    {
      if ((strncmp(file[i], "export ", 7)) == 0)
	{
	  if ((cmd = get_cmd(file[i])) == NULL)
	    {
	      dprintf(STDERR_FILENO, "Syntax errors on .conf line %i\n", i + 1);
	      dprintf(STDERR_FILENO, "Status: export TEST=%cbin%c\n", '"', '"');
	      return (-1);
	    }
	  builtin_setenv(cmd, data->env, data);
	  get_free_tab(cmd, 3);
	}
      i++;
    }
  return (0);
}
