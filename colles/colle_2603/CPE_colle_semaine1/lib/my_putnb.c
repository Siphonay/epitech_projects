/*
** my_putnb.c for in /home/simon/CPE_colle_semaine1/lib
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 16:05:11 2016 Simon Pedrono
** Last update Tue Apr 26 17:58:26 2016 Simon Pedrono
*/

#include "tree.h"

void	my_putnbr(int nb)
{
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
