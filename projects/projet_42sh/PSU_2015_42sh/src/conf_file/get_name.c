/*
** alias2.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/conf_file/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Sat Jun  4 22:02:55 2016 Nolann Méléard
** Last update Sat Jun  4 23:45:49 2016 Nolann Méléard
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mysh.h"

char	*get_name(char *str)
{
  char	*name;
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  while (str[i] != '=' && str[i] != '\0')
    i++;
  if (str[i] == '\0')
    return (NULL);
  if ((name = malloc(i + 1 * sizeof(char))) == NULL)
    return (NULL);
  name = memset(name, '\0', (size_t)(i + 1));
  name = strncpy(name, str, (size_t) i);
  return (name);
  }

int	check_for_av1(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '=')
    i++;
  i++;
  if (str[i] != 39)
    return (-1);
  while (str[i] != '\0')
    i++;
  i--;
  if (str[i] != 39)
    return (-1);
  return (0);
}

int	check_for_avx(char **av)
{
  int	i;
  int	j;

  i = 2;
  j = 0;
  while (av[i] != NULL)
    {
      while (av[i][j] != '\0')
	{
	  if (av[i][j] == 39 && (av[i][j + 1] == '\0' || av[i + 1] == NULL))
	    return (i);
	  j++;
	}
      i++;
    }
  i = -1;
  return (i);
}

int	count_for_alias(char **av)
{
  int	i;
  int	c;

  i = 1;
  c = 0;
  while (av[1][i] != '\0')
    {
      if (av[1][i] == 39)
	c++;
      i++;
    }
  if (c > 2 || c <= 0 || (c == 1 && av[2] == NULL)
    || (c == 2 && av[2] != NULL))
    return (-1);
  if (c == 2 && (check_for_av1(av[1])) == -1)
    return (-1);
  else if (c == 2)
    return (1);
  if (c == 1)
    c = check_for_avx(av);
  if (c == -1)
    return (-1);
  return (c);
}

int	count_len_tab(char **av)
{
  int	i;
  int	len;
  int	c;

  i = 0;
  c = 0;
  len = 0;
  while (av[i])
    {
      c = strlen(av[i]);
      if (c > len)
	len = c;
      i++;
    }
  return (len);
}
