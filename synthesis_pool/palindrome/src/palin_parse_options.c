/*
** palin_parse_options.c for palindrome in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Jun 17 09:34:03 2016 Alexis Viguié
** Last update Sat Jun 18 11:34:10 2016 Alexis Viguié
*/

#include <string.h>
#include <stdlib.h>
#include "palin.h"

t_options	initialize_default_options()
{
  t_options	default_options;

  default_options.help = default_options.pal = default_options.num =
    default_options.invalid_arg  = false;
  default_options.base = DEFAULT_BASE;
  default_options.imin = DEFAULT_MIN;
  default_options.imax = DEFAULT_MAX;
  return (default_options);
}

bool	is_num(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      if (!counter && str[counter] == '-')
	counter++;
      if (!str[counter] || (str[counter] < '0' || str[counter] > '9'))
	return (false);
      counter++;
    }
  return (true);
}

t_options	parse_numbers(char **av, int counter, t_options options_ret)
{
  if (!strcmp(OPTION_B, av[counter]))
    {
      counter++;
      if (!(options_ret.invalid_arg = (!av[counter] || !is_num(av[counter]))))
	options_ret.base = atoi(av[counter]);
    }
  else if (!strcmp(OPTION_MIN, av[counter]))
    {
      counter++;
      if (!(options_ret.invalid_arg = (!av[counter] || !is_num(av[counter]))))
	    options_ret.imin = atoi(av[counter]);
    }
  else if (!strcmp(OPTION_MAX, av[counter]))
    {
      counter++;
      if (!(options_ret.invalid_arg = (!av[counter] || !is_num(av[counter]))))
	options_ret.imax = atoi(av[counter]);
    }
  else
    options_ret.invalid_arg = true;
  return (options_ret);
}

t_options	palin_parse_options(char **av)
{
  t_options	options_ret;
  int		counter;

  options_ret = initialize_default_options();
  if (!av[0] || (options_ret.help = !strcmp(OPTION_H, av[0])))
    return (options_ret);
  counter = 0;
  while (av[counter] && !options_ret.invalid_arg)
    {
      if (!strcmp(OPTION_N, av[counter]) || !strcmp(OPTION_P, av[counter]))
	{
	  options_ret.num += !strcmp(OPTION_N, av[counter]);
	  options_ret.pal += !strcmp(OPTION_P, av[counter]);
	  counter++;
	  if (av[counter] && is_num(av[counter]))
	    options_ret.value = atoi(av[counter]);
	  else
	    options_ret.invalid_arg = true;
	}
      else
	  options_ret = parse_numbers(av, counter++, options_ret);
      if (av[counter])
	counter++;
    }
  return (options_ret);
}
