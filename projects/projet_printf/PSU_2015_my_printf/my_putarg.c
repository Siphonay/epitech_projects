/*
** my_putarg.c for my printf in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov 12 15:47:35 2015 Alexis Viguié
** Last update Mon Nov 16 23:36:03 2015 Alexis Viguié
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_getneg(int num)
{
  write(1, "-", 1);
  return (-(num));
}

void	my_put_base_str(int nb, char *base)
{
  char	*affnum;

  affnum = my_int_to_base_str(nb, base);
  my_putstr(affnum);
  free(affnum);
}

void	my_putptr(void *ptr)
{
  int	ptradd;

  ptradd = &ptr;
  write(1, "0x", 2);
  my_put_base_str(ptradd, HEXA_LOWERCASE);
}

void	my_putarg(int arg, char argtype)
{
  if (arg < 0)
    arg = my_getneg(arg);
  if (argtype == 'd' || argtype == 'i')
    my_put_base_str(arg, DECIMAL);
  else if (argtype == 'X')
    my_put_base_str(arg, HEXA_UPPERCASE);
  else if (argtype == 'x')
    my_put_base_str(arg, HEXA_LOWERCASE);
  else if (argtype == 'o')
    my_put_base_str(arg, OCTAL);
  else if (argtype == 'b')
    my_put_base_str(arg, BINARY);
  else if (argtype == 'c')
    write(1, &arg, 1);
  else if (argtype == 'p')
    {
      write(1, "0x", 2);
      my_put_base_str(arg, HEXA_LOWERCASE);
    }
    write(1, "%", 1);
}
