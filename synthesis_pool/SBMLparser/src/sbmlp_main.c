/*
** sbmlp_main.c for SBMLparser in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 13 09:44:25 2016 Alexis Viguié
** Last update Wed Jun 15 10:18:19 2016 Alexis Viguié
*/

#include "sbml.h"

int		main(int __attribute__((unused)) ac, char **av)
{
  t_options	options;

  options = parse_options(&av[1]);
  if (!options.correct)
    return (sbml_error_handling(options, av[1]));
  if (options.help)
    return (print_help());
  return (sbml_parsing(options));
}
