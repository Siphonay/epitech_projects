/*
** my_isneg.c for my isneg in /home/viguie_a/rendu_j03/Piscine_C_J03
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Wed Sep 30 12:11:03 2015 Alexis Viguié
** Last update Sat Oct 24 23:40:33 2015 Alexis Viguié
*/

#include "my.h"

int	my_isneg(int nb)
{
  if (nb < 0)
      my_putchar('N');
  else
      my_putchar('P');
  return (0);
}
