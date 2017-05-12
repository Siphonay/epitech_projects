/*
** epur_str.c for epur_str in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Tue Apr  5 15:25:08 2016 thibault derbre
** Last update Tue Apr 12 15:01:21 2016 thibault derbre
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

int	check_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (0);
      i++;
    }
  return (1);
}

char	*epur_src(char *str)
{
  int	i;
  int	j;
  char	*src;

  ((src = malloc((my_strlen(str)) + 1 * sizeof(char))) == NULL ? exit(1) : 0);
  (1 ? j = 0, i = 0 : 0);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  src[j] = ' ';
	  while (str[i] == ' ' || str[i] == '\t')
	    i++;
	}
      else
	src[j] = str[i++];
      j++;
    }
  (src[j - 1] == ' ' ? src[j - 1] = '\0' : (src[j] = '\0'));
  return (src);
}

char	*epur_str(char *str)
{
  str = epur_src(str);
  return (str);
}
