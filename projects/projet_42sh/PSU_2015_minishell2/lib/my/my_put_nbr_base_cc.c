/*
** my_put_nbr_base_cc.c for base_cc in /home/zaza/rendu/PSU_2015_my_printf/
**
** Made by Thibault Derbré
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Nov 16 23:07:06 2015 Thibault Derbré
** Last update Mon Apr  4 20:31:43 2016 thibault derbre
*/

#include "my.h"

int	my_put_nbr_base_cc(char *base, long nb)
{
  int	i;
  long	d;
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
