/*
** sam_strtab.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 25 17:17:39 2016 Alexis Viguié
** Last update Mon Jan 25 18:17:07 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "sam.h"

unsigned int	check_separator(char comp, char *separator)
{
  unsigned int	counter;

  counter = 0;
  while (separator[counter] && separator[counter] != comp)
    counter++;
  return (separator[counter] == comp);
}

unsigned int	check_wordcount(char *src, char *separator)
{
  unsigned int	counter;
  unsigned int	word_counter;

  counter = 0;
  word_counter = 0;
  while (src[counter])
    {
      if ((!counter && !check_separator(src[counter], separator)) ||
	  (check_separator(src[counter], separator) &&
	   !check_separator(src[counter + 1], separator)))
	word_counter++;
      counter++;
    }
  return (word_counter);
}

char		**emer_free_wordtab(char **wordtab, unsigned int pos_tofree)
{
  unsigned int	counter;

  counter = 0;
  while (counter < pos_tofree)
    {
      free(wordtab[counter]);
      counter++;
    }
  free(wordtab);
  return (NULL);
}

char		**build_tab(char **inittab, char *src, char *separator)
{
  unsigned int	counter;
  unsigned int	counter2;
  unsigned int	strtab_pos;

  counter = 0;
  counter2 = 0;
  strtab_pos = 0;
  while (src[counter])
    {
      while (check_separator(src[counter], separator))
	counter++;
      if (src[counter])
	{
	  counter2 = counter;
	  while (!check_separator(src[counter2], separator))
	    counter2++;
	  if ((inittab[strtab_pos] =
	       sam_strncpy(&src[counter], -(counter - counter2))) == NULL)
	    return (emer_free_wordtab(inittab, strtab_pos));
	  strtab_pos++;
	  counter = counter2;
	}
    }
  return (inittab);
}

char		**sam_strtab(char *src, char *separator)
{
  char		**ret_strtab;

  if ((ret_strtab =
       malloc(sizeof(char*) * (check_wordcount(src, separator + 1)))) == NULL)
    return (NULL);
  ret_strtab[check_wordcount(src, separator)] = NULL;
  return (build_tab(ret_strtab, src, separator));
}
