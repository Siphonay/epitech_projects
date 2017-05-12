/*
** base.c for base in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 18:02:54 2016 thibault derbre
** Last update Mon Apr 11 17:00:07 2016 thibault derbre
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

char	*my_strcat_cd(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  (1 ? j = my_strlen(dest), i = my_strlen(src) : 0);
  if ((str = malloc((i + j) + 2 * sizeof(char))) == NULL)
    return (NULL);
  (1 ? j = 0, i = 0 : 0);
  while (src[i] != '\0')
    {
      str[j] = src[i];
      i++;
      j++;
    }
  str[j] = '/';
  j++;
  i = 0;
  while (dest[i] != '\0')
    {
      str[j] = dest[i];
      i++;
      j++;
    }
  str[j] = '\0';
  return (str);
}
