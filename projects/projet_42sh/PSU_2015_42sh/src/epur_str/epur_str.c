/*
** epur_str.c for epur_str in /home/zaza/rendu/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed May  4 15:38:27 2016 thibault derbre
** Last update Sun Jun  5 22:30:29 2016 thibault derbre
*/

#include <string.h>
#include <stdlib.h>

char	*epur_str(char *str)
{
  int	i;
  int	j;
  char	*src;

  if ((src = malloc(((strlen(str) + 1)* sizeof(char)))) == NULL)
    return (NULL);
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
  if (j == 0)
    return (NULL);
  (src[j - 1] == ' ' ? src[j - 1] = '\0' : (src[j] = '\0'));
  return (src);
}
