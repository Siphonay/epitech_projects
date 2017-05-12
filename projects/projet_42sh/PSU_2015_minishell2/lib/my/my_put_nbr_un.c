/*
** my_put_nbr_un.c for my_put_nbr_un.c in /home/zaza/rendu/PSU_2015_my_printf/
**
** Made by Thibault Derbré
** Login   <derbre_t@epitech.eu>
**
** Started on  Thu Nov 12 11:06:11 2015 Thibault Derbré
** Last update Mon Apr  4 20:31:33 2016 thibault derbre
*/

#include "my.h"

unsigned int	my_put_nbr_un(unsigned int nb)
{
  unsigned int	d;
  int	a;

  d = 1;
  a = 1;
  if (nb == 0)
    my_putchar('0');
  while ((nb / d) >= 10)
    {
      d = d * 10;
      a++;
    }
  while (d > 0)
    {
      my_putchar((nb / d) % 10 + '0');
      d = d / 10;
    }
  return (a);
}
