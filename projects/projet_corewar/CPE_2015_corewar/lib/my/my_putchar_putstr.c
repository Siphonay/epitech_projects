/*
** my_putchar_putstr.c for putchar and putstr in /home/merlin/rendu/CPE/CPE_2015_corewar
**
** Made by Victor Herlin
** Login   <merlin@epitech.net>
**
** Started on  Fri Mar 25 15:55:32 2016 Victor Herlin
** Last update Fri Mar 25 15:56:41 2016 Victor Herlin
*/

#include <asm.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
