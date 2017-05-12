/*
** my_strlen.c for my_strlen.c in /home/derbre_t/rendu
**
** Made by thibault derbre
** Login   <derbre_t@epitech.net>
**
** Started on  Fri Oct  2 12:13:21 2015 thibault derbre
** Last update Fri Nov 13 15:20:09 2015 Thibault Derbré
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	 n;

  n = 0;
  while (str[n] != '\0')
    {
      n++;
    }
  return (n);
}
