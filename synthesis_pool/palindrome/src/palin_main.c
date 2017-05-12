/*
** palin_main.c for palindrome in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jun 16 18:23:50 2016 Alexis Viguié
** Last update Fri Jun 17 15:43:53 2016 Alexis Viguié
*/

#include "palin.h"

int		main(int __attribute__((unused)) ac, char **av)
{
  t_options	options;

  options = palin_parse_options(&av[1]);
  if (!palin_validate_options(options))
      return (PALIN_EXIT_FAILURE);
  if (options.help)
      return (palin_print_help());
  else
    return (palin_sarah(options));
}
