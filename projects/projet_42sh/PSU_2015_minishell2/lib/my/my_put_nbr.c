/*
** my_put_nbr.c for my_put_nbr.c in /home/derbre_t/rendu
**
** Made by thibault derbre
** Login   <derbre_t@epitech.net>
**
** Started on  Thu Oct  1 22:02:54 2015 thibault derbre
** Last update Mon Apr  4 20:30:33 2016 thibault derbre
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	d;
  int	a;

  d = 1;
  a = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
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
