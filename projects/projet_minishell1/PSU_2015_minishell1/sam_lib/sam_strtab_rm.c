/*
** sam_strtab_rm.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 18:18:49 2016 Alexis Viguié
** Last update Wed Jan 27 23:34:40 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"

char	**emer_free_tab_init_rm(char **src)
{
  sam_free_strtab(src);
  return (NULL);
}

char		**emer_free_tab_rm(char **src, char **tab)
{
  unsigned int	counter;

  sam_free_strtab(src);
  counter = 0;
  while (tab[counter])
    {
      free(tab[counter]);
      counter++;
    }
  return (NULL);
}

char		**sam_strtab_rm(char **src, unsigned int index)
{
  unsigned int	counter;
  unsigned int	counter2;
  char		**tab_ret;

  if (index > (sam_strtablen(src) - 1))
    return (src);
  if ((tab_ret = malloc(sizeof(char*) * sam_strtablen(src))) == NULL)
    return (emer_free_tab_init_rm(src));
  tab_ret[sam_strtablen(src) - 1] = NULL;
  counter = 0;
  counter2 = 0;
  while (src[counter2])
    {
      if (counter2 == index)
	counter2++;
      if ((tab_ret[counter] =
	   sam_strncpy(src[counter2], sam_strlen(src[counter]))) == NULL)
	return (emer_free_tab_rm(src, tab_ret));
      counter++;
      counter2++;
    }
  sam_free_strtab(src);
  return (tab_ret);
}
