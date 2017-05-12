/*
** my_int_to_hex_str.c for my printf in /home/sam/projet_printf/PSU_2015_my_printf
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov 12 17:27:47 2015 Alexis Viguié
** Last update Fri Nov 13 16:36:55 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "my.h"

char	*my_int_to_base_str(int nb, char *base)
{
  int	baselen;
  int	counter;
  int	length;
  int	operated_number;
  char	*return_str;

  baselen = my_strlen(base);
  operated_number = nb;
  length = 0;
  while (nb != 0)
    {
      length++;
      nb /= baselen;
    }
  return_str = malloc((length + 1) * sizeof(char));
  if (!return_str)
    return (NULL);
  counter = 0;
  while (counter < length)
    {
      return_str[length - (counter + 1)] = base[operated_number % baselen];
      operated_number /= baselen;
      counter++;
    }
  return_str[length] = '\0';
  return (return_str);
}
