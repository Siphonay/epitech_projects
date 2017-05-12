/*
** my_put_nbr.c for put number in /home/viguie_a/rendu_j05
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Fri Oct  2 11:54:46 2015 Alexis Viguié
** Last update Mon Nov 16 11:06:13 2015 Alexis Viguié
*/

#include <unistd.h>

void	my_put_nbr(int nb)
{
  int	nbr_dsp;
  int	divider;
  char	dispnum;

  if (nb < 0)
    {
      write(1, "-", 1);
      nb = -nb;
    }
  divider = 1;
  while ((nb / divider) >= 10)
    divider = divider * 10;
  while (divider > 0)
    {
      nbr_dsp = (nb / divider) % 10;
      dispnum = 48 + nbr_dsp;
      write(1, &dispnum, 1);
      divider = divider / 10;
    }
}
