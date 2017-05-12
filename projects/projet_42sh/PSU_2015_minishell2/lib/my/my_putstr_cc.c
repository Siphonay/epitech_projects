/*
** my_putstr_cc.c for my_putstr_cc in /home/zaza/rendu/PSU_2015_my_printf/
**
** Made by Thibault Derbré
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Nov 16 21:14:19 2015 Thibault Derbré
** Last update Tue Nov 17 11:56:03 2015 Thibault Derbré
*/

#include "my.h"

void	enc_plus_cc(char *str, int *i)
{
  if (str[*i] < 7)
    {
      my_putchar('\\');
      my_putstr("00");
      my_put_nbr_base("01234567", str[*i]);
      *i = *i + 1;
    }
  else if (str[*i] >= 8)
    {
      my_putchar('\\');
      my_putchar('0');
      my_put_nbr_base("01234567", str[*i]);
      *i = *i + 1;
    }
  else if (str[*i] > 64)
    {
      my_putchar('\\');
      my_put_nbr_base("01234567", str[*i]);
      *i = *i + 1;
    }
}

int	my_putstr_cc(char *str)
{
  int	i;
  int	a;

  a = my_strlen(str);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	enc_plus_cc(str, &i);
      else
	{
	  my_putchar(str[i]);
	  i++;
	}
    }
  return (a);
}
