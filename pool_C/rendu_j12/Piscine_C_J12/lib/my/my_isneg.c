/*
** my_isneg.c for my isneg in /home/viguie_a/rendu_j03/Piscine_C_J03
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Wed Sep 30 12:11:03 2015 Alexis Viguié
** Last update Tue Oct  6 13:30:51 2015 Alexis Viguié
*/

int	my_isneg(int nb)
{
  if (nb < 0)
      my_putchar('N');
  else
      my_putchar('P');
  return (0);
}
