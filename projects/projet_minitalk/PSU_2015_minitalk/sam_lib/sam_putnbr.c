/*
** sam_putnbr.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Feb  8 17:17:39 2016 Alexis Viguié
** Last update Mon Feb  8 17:22:53 2016 Alexis Viguié
*/

#include <unistd.h>

void	sam_putnbr(int nbr, int fd)
{
  char	cur_digit;
  int	divider;

  if (nbr < 0)
    {
      write(fd, "-", 1);
      nbr = -nbr;
    }
  divider = 1;
  while ((nbr / divider) >= 10)
    divider *= 10;
  while (divider)
    {
      cur_digit = ((nbr / divider) % 10) + '0';
      write(fd, &cur_digit, 1);
      divider /= 10;
    }
}
