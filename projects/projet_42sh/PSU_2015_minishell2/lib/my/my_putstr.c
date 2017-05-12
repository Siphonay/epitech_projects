/*
** my_putstr.c for my_putstr in /home/zaza/rendu/PSU_2015_my_printf/
**
** Made by Thibault Derbré
** Login   <derbre_t@epitech.eu>
**
** Started on  Thu Nov  5 18:23:51 2015 Thibault Derbré
** Last update Mon Nov 16 10:32:05 2015 Thibault Derbré
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;
  int	a;

  a = my_strlen(str);
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (a);
}
