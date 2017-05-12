/*
** delete_token_spaces.c for delete_token_spaces  in /home/zaza/rendu/PSU_2015_42sh/src/epur_str/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed May 25 14:56:20 2016 thibault derbre
** Last update	Sat Jun 04 17:18:40 2016 pedron_s
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mysh.h"

int	my_checkchar(char *str, int i)
{
  if ((str[i] == '<' && str[i - 1] != '<') || (str[i] == '>'
       && str[i - 1] != '>') || (str[i] == '&' && str[i - 1] != '&')
      || (str[i] == '|' && str[i - 1] != '|'))
    return (1);
  return (0);
}

int	my_checkone(char *str, int i)
{
  if ((str[i] == '<') || (str[i] == '>') || (str[i] == '&')
       || (str[i] == '|'))
    return (1);
  return (0);
}

int	my_checksndchar(char *str, int i)
{
  if ((str[i - 1] == '<' && str[i] != '<') || (str[i - 1] == '>'
       && str[i] != '>') || (str[i - 1] == '&'
       && str[i] != '&') || (str[i - 1] == '|' && str[i] != '|'))
    return (1);
  return (0);
}

char	*delete_token_spaces(char *str)
{
  int	i;
  int	f;
  char	*src;

  if ((src = malloc((strlen(str) * 2) * sizeof(char))) == NULL)
    return (NULL);
  i = f = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ')
	{
	  if (i > 0)
	      my_checkchar(str, i) == 1 ? src[f++] = ' ' : 0;
	  else
	      my_checkone(str, i) == 1 ? src[f++] = ' ' : 0;
	  if (i > 0)
	      my_checksndchar(str, i) == 1 ? src[f++] = ' ' : 0;
	}
      src[f] = str[i];
      f++;
      i++;
    }
  free(str);
  src[f] = '\0';
  return (src);
}
