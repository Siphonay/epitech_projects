/*
** small_instring.c for small_instring in /home/coutar_b/rendu/Piscine_C_bistromathique/Piscine_C_bistromathique_test
** 
** Made by Thomas Coutard
** Login   <coutar_b@epitech.net>
** 
** Started on  Wed Oct 28 10:50:27 2015 Thomas Coutard
** Last update Wed Oct 28 10:51:11 2015 Thomas Coutard
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char    *small_instring(int len, char *num)
{
  char  *ret_str;
  int   counter;

  counter = 0;
  ret_str = malloc(len * sizeof(char) + 1);
  if (ret_str == NULL)
    return (ret_str);
  while (num[counter] != '\0')
    {
      ret_str[counter] = num[counter];
      counter++;
    }
  while (counter < len)
    {
      ret_str[counter] = '0';
      counter++;
    }
  ret_str[counter] = '\0';
  return (ret_str);
}
