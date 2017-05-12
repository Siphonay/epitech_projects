/*
** my_putstr.c for  in /home/viguie_a/rendu_j04
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Thu Oct  1 17:15:38 2015 Alexis Viguié
** Last update Thu Nov  5 16:13:17 2015 Alexis Viguié
*/

#include "my.h"

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}
