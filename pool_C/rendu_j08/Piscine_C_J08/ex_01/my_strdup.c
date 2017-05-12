/*
** my_strdup.c for my strdup in /home/viguie_a/rendu_j08/ex_01
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Wed Oct  7 11:20:13 2015 Alexis Viguié
** Last update Wed Oct  7 14:59:41 2015 Alexis Viguié
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  char	*dest;
  int	counter;

  dest = malloc(my_strlen(src));
  counter = 0;
  while (counter < my_strlen(src))
    {
      dest[counter] = src[counter];
      counter++;
    }
  return(dest);
}
