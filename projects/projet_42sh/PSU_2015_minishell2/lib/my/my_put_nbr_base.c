/*
** my_put_nbr_base.c for base in /home/zaza/rendu/PSU_2015_my_printf/
**
** Made by Thibault Derbré
** Login   <derbre_t@epitech.eu>
**
** Started on  Thu Nov 12 11:06:53 2015 Thibault Derbré
** Last update Mon Apr  4 20:31:23 2016 thibault derbre
*/

#include "my.h"

int	my_put_nbr_base(char *base, int nb)
{
  int	i;
  int	d;
  int	lenbase;
  int	a;

  a = 1;
  lenbase = my_strlen(base);
  d = 1;
  if (nb < 0)
    nb = -nb;
  if (nb == 0)
    my_putchar('0');
  while ((nb / d) >= lenbase)
    {
      d = d * lenbase;
      a++;
    }
  while (d > 0)
    {
      i = (nb / d) % lenbase;
      my_putchar(base[i]);
      d = d / lenbase;
    }
  return (a);
}
