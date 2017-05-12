/*
** free_wordtab.c for SBMLparser in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 13 10:48:03 2016 Alexis Viguié
** Last update Mon Jun 13 10:49:00 2016 Alexis Viguié
*/

#include <stdlib.h>

void	free_wordtab(char **wordtab)
{
  int	counter;

  counter = 0;
  while (wordtab[counter])
    {
      free(wordtab[counter]);
      counter++;
    }
  free(wordtab);
}
