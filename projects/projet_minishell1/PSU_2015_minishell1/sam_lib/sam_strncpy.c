/*
** sam_strncpy.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Jan 17 19:24:30 2016 Alexis Viguié
** Last update Sun Jan 17 19:34:10 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"

char		*sam_strncpy(char *param_string, unsigned int c_lim)
{
  unsigned int	counter;
  char		*ret_str;

  if (c_lim > sam_strlen(param_string))
    c_lim = sam_strlen(param_string);
  counter = 0;
  if ((ret_str = malloc(sizeof(char) * (c_lim + 1))) == NULL)
    return (NULL);
  ret_str[c_lim] = '\0';
  while (counter < c_lim)
    {
      ret_str[counter] = param_string[counter];
      counter++;
    }
  return (ret_str);
}
