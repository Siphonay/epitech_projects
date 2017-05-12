/*
** sam_free_strtab.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 25 18:13:17 2016 Alexis Viguié
** Last update Mon Jan 25 18:14:21 2016 Alexis Viguié
*/

#include <stdlib.h>

void		sam_free_strtab(char **strtab)
{
  unsigned int	counter;

  counter = 0;
  while (strtab[counter])
    {
      free(strtab[counter]);
      counter++;
    }
  free(strtab);
}
