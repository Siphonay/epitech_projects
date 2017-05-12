/*
** sam_strcmp.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 18 16:50:47 2016 Alexis Viguié
** Last update Wed Jan 20 16:00:47 2016 Alexis Viguié
*/

#include "sam.h"

unsigned int   	sam_strcmp(char *pstring_1, char *pstring_2)
{
  unsigned int	counter;

  if (sam_strlen(pstring_1) != sam_strlen(pstring_2))
    return (1);
  counter = 0;
  while (pstring_1[counter] && pstring_2[counter])
    {
      if (pstring_1[counter] != pstring_2[counter])
	return (1);
      counter++;
    }
  return (0);
}
