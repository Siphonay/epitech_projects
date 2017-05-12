/*
** lb_putnbr.c for bootstrap lemin in /home/sam/Rendu/Projets/projet_lemin/CPE_2015_lemin_bootstrap
**
** Made by
** Login   <sam@epitech.net>
**
** Started on  Wed Apr  6 14:05:25 2016
** Last update Wed Apr  6 14:08:57 2016 
*/

#include <unistd.h>

void	lb_putnbr(int nbr)
{
  char	cur_digit;
  int	divider;

  if (nbr < 0)
    {
      write(1, "-", 1);
      nbr = -nbr;
    }
  divider = 1;
  while ((nbr / divider) >= 10)
    divider *= 10;
  while (divider)
    {
      cur_digit = ((nbr / divider) % 10) + '0';
      write(1, &cur_digit, 1);
      divider /= 10;
    }
}
