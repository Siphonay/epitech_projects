/*
** append_to_wordtab.c for SBMLparser in /home/sam/Rendu/Piscine_S/projet_1/SBMLparser
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jun 15 10:43:44 2016 Alexis Viguié
** Last update Wed Jun 15 10:49:31 2016 Alexis Viguié
*/

#include <stdlib.h>

size_t		wordtablen(char **wordtab)
{
  size_t	counter;

  counter = 0;
  while (wordtab[counter])
    counter++;
  return (counter);
}

char		**append_to_wordtab(char **wordtab, char *str_to_append)
{
  size_t	wlen;

  if (!(wordtab = realloc(wordtab, sizeof(char*) *
			  ((wlen = wordtablen(wordtab)) + 1))))
    return (NULL);
  wordtab[wlen] = str_to_append;
  return (wordtab);
}
