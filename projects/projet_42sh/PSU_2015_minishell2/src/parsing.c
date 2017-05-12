/*
** parsing.c for parsing in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 11:49:15 2016 thibault derbre
** Last update Sat Apr  9 11:54:10 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

char	*delete_token_spaces(char *str)
{
  int	i;
  int	f;
  char	*src;

  ((src = malloc((my_strlen(str)) + 1 * sizeof(char))) == NULL ? exit(1) : 0);
  (1 ? i = 0, f = 0 : 0);
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  if (str[i + 1] == '>' || str[i + 1] == '<'
	      || str[i + 1] == '|' || str[i + 1] == '&' || str[i + 1] == ';')
	    i++;
	  else if (str[i - 1] == '>' || str[i - 1] == '<' || str[i - 1] == '|'
		   || str[i - 1] == '&' || str[i - 1] == ';')
	    i++;
	}
      src[f] = str[i];
      i++;
      f++;
    }
  src[f] = '\0';
  return (src);
}

int	check_tokens(char *str, int *j, int *f, int *compt)
{
  if (*f == 0)
    {
      if (str[*j + 1] == '>' || str[*j + 1] == '<' || str[*j + 1] == '|'
	  || str[*j + 1] == '&' || str[*j + 1] == ';')
	{
	  *f = 1;
	  (*j)++;
	  (*compt)++;
	  return (1);
	}
    }
  return (0);
}

int	check_cmd(char *str, int *j, int *f, int *compt)
{
  if (*f == 1)
    {
      if (str[*j + 1] != '>' && str[*j + 1] != '<' && str[*j + 1] != '|'
	  && str[*j + 1] != '&' && str[*j + 1] != ';')
	{
	  *f = 0;
	  (*compt)++;
	  (*j)++;
	  return (1);
	}
    }
  return (0);
}
