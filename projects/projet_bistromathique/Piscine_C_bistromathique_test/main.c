/*
** main.c for main in /home/coutar_b/rendu/Piscine_C_bistromathique/Piscine_C_bistromathique_test
**
** Made by Thomas Coutard
** Login   <coutar_b@epitech.net>
**
** Started on  Fri Oct 23 16:08:29 2015 Thomas Coutard
** Last update Thu Oct 29 17:17:24 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromathique.h"
#include "my.h"

int	main(int ac, char **av)
{
  char	*expr;
  int	size;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len\n");
      return (1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  size = my_getnbr(av[3]);
  expr = get_expr(size);
  my_putstr(eval_expr(av[1], av[2], expr, size));
  return (0);
}
