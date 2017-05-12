/*
** my_power_rec.c for  in /home/viguie_a/rendu_j05
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Fri Oct  2 21:13:21 2015 Alexis Viguié
** Last update Fri Oct  2 21:34:40 2015 Alexis Viguié
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    return (1);
  else
    return (nb * my_power_rec(nb,power - 1));
}
