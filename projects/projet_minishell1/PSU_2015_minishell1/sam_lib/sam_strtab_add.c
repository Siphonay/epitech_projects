/*
** sam_strtab_add.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 18:01:40 2016 Alexis Viguié
** Last update Wed Jan 27 23:35:11 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"

char		**emer_free_tab_add(char **src, char **tab)
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

char		**emer_free_tab_init_add(char **src)
{
  sam_free_strtab(src);
  return (NULL);
}

char		**sam_strtab_add(char **src, char *str_add)
{
  unsigned int	counter;
  char		**tab_ret;

  if ((tab_ret = malloc(sizeof(char*) * (sam_strtablen(src) + 2))) == NULL)
    return (emer_free_tab_init_add(src));
  tab_ret[sam_strtablen(src) + 1] = NULL;
  if ((tab_ret[sam_strtablen(src)] =
       sam_strncpy(str_add, sam_strlen(str_add))) == NULL)
    {
      free(tab_ret);
      sam_free_strtab(src);
      return (NULL);
    }
  counter = 0;
  while (src[counter])
    {
      if ((tab_ret[counter] =
	   sam_strncpy(src[counter], sam_strlen(src[counter]))) == NULL)
	return (emer_free_tab_add(src, tab_ret));
      counter++;
    }
  sam_free_strtab(src);
  return (tab_ret);
}
