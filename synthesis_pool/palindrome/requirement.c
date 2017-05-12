/*
** requirement.c for palindrome in /home/sam/Rendu/Piscine_S/palindrome
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jun 16 09:54:09 2016 Alexis Viguié
** Last update Thu Jun 16 18:00:58 2016 Alexis Viguié
*/

int	my_factrec_synthesis(int nb)
{
  int	res;
  int	fact;
  int	fact_s;

  if (nb < 0)
    return (0);
  else if (nb < 2)
    return (1);
  if (!(fact_s = my_factrec_synthesis(nb - 1)))
    return (0);
  else
    fact = fact_s;
  res = nb * fact_s;
  if (res / fact != nb)
    return (0);
  else
    return (res);
}

int	my_squareroot_synthesis(int nb)
{
  int	res;
  int	nb_b;

  res = 0;
  nb_b = nb;
  while (nb_b >= 0)
    {
      nb_b -= res;
      nb_b -= ++res;
    }
  res--;
  if (res * res == nb)
    return (res);
  else
    return (-1);
}
