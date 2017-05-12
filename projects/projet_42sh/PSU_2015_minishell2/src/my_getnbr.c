/*
** my_getnbr.c for my_getnbr in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr 11 20:46:04 2016 thibault derbre
** Last update Mon Apr 11 20:49:13 2016 thibault derbre
*/

#include <stdlib.h>
#include "mysh.h"

int	get_nb(char *str, int i)
{
  int	res;
  int	k;

  res = 0;
  k = 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      res = res + (str[i] - 48) * k;
      i--;
      if (i == -1)
	return (res);
      k = k * 10;
    }
  return (res);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;
  int	f;

  res = 0;
  i = 0;
  f = 0;
  while (str[i] < '0' || str[i] > '9')
    i++;
  if (i > 0)
    {
      if (str[i - 1] == '-')
	f = 1;
    }
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  i--;
  res = get_nb(str, i);
  if (f == 1)
    res = -res;
  return (res);
}
