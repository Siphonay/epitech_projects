/*
** sam_strtabcpy.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 17:36:39 2016 Alexis Viguié
** Last update Wed Jan 27 17:47:23 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"

void		emer_free_tab(char **strtab)
{
  unsigned int	counter;

  counter = 0;
  while (strtab[counter])
    {
      free(strtab[counter]);
      counter++;
    }
}

char		**sam_strtabcpy(char **src)
{
  unsigned int	counter;
  char		**tab_ret;

  if ((tab_ret = malloc(sizeof(char*) * (sam_strtablen(src) + 1))) == NULL)
    return (NULL);
  tab_ret[sam_strtablen(src)] = NULL;
  counter = 0;
  while (src[counter])
    {
      if ((tab_ret[counter] =
	   sam_strncpy(src[counter], sam_strlen(src[counter]))) == NULL)
	{
	  emer_free_tab(tab_ret);
	  return (NULL);
	}
      counter++;
    }
  return (tab_ret);
}
