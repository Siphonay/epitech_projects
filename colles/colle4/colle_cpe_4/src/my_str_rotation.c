/*
** my_str_rotation.c for my transformer in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 09:13:32 2015 Alexis Viguié
** Last update Fri Dec 18 10:25:42 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "transformer.h"

char	*my_str_rotation(char *str)
{
  char	*str_ret;
  int	counter;

  if ((str_ret = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    {
      my_putstr_err("MALLOC ERROR!");
      exit(1);
    }
  str_ret[my_strlen(str)] = '\0';
  counter = 0;
  while (str[counter + 1])
    {
      str_ret[counter + 1] = str[counter];
      counter++;
    }
  str_ret[0] = str[counter];
  return (str_ret);
}
