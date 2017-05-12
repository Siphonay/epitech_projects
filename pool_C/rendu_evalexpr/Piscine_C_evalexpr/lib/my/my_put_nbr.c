/*
** my_put_nbr.c for put number in /home/viguie_a/rendu_j05
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Fri Oct  2 11:54:46 2015 Alexis Viguié
** Last update Wed Oct 14 18:51:02 2015 Alexis Viguié
*/

int	my_put_nbr(int nb)
{
  int	nbr_dsp;
  int	divider;

  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  divider = 1;
  while ((nb / divider) >= 10)
    divider = divider * 10;
  while (divider > 0)
    {
      nbr_dsp = (nb / divider) % 10;
      my_putchar(48 + nbr_dsp);
      divider = divider / 10;
    }
}
