/*
** tetris_putnbr.c for tetris_putnbr in /home/guillaume/Bureau/code/tp/unix/PSU_2015_tetris/tetris_lib
**
** Made by Guillaume Morin
** Login   <guillaume@epitech.net>
**
** Started on  Thu Feb 25 12:19:44 2016 Guillaume Morin
** Last update Thu Mar  3 16:39:40 2016 Alexis Viguié
*/

#include <unistd.h>

void	tetris_putnbr(int nbr)
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
