/*
** main.c for  in /home/simon/colle_1_2603/srcs
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 14:09:12 2016 Simon Pedrono
** Last update Tue Apr 26 17:57:59 2016 Simon Pedrono
*/

#include <stdlib.h>
#include "tree.h"

int		main(int __attribute__((unused)) ac, char **av)
{
  t_options	options;

  options = my_parser(av);
  options = my_pars_L(av, options);
  if (options.usage)
    {
      print_usage(options);
      return (1);
    }
  disp_tree(av, options);
  return (0);
}
