/*
** sam_strncat.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 18 14:32:44 2016 Alexis Viguié
** Last update Mon Jan 18 15:03:09 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"

char		*sam_strncat(char *str_1, char *str_2, unsigned int c_lim)
{
  unsigned int	ret_len;
  char		*ret_str;
  unsigned int	counter;

  ret_len = sam_strlen(str_1) + c_lim;
  if (!(ret_str = malloc(sizeof(char) * (ret_len + 1))))
      return (NULL);
  counter = 0;
  while (str_1[counter])
    {
      ret_str[counter] = str_1[counter];
      counter++;
    }
  while (str_2[counter - sam_strlen(str_1)] &&
	 (counter - sam_strlen(str_1)) < c_lim)
    {
      ret_str[counter] = str_2[counter - sam_strlen(str_1)];
      counter++;
    }
  ret_str[counter] = '\0';
  return (ret_str);
}
