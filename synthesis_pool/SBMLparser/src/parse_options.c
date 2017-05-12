/*
** parse_options.c for SBMLparser in /home/sam/Rendu/Piscine_S/projet_1/SBMLparser
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Jun 14 15:36:39 2016 Alexis Viguié
** Last update Wed Jun 15 10:16:17 2016 Alexis Viguié
*/

#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include "sbml.h"

int	get_option(char *arg)
{
  if (!strcmp(arg, OPTION_I_STR))
    return (OPTION_I);
  else if (!strcmp(arg, OPTION_E_STR))
    return (OPTION_E);
  else if (!strcmp(arg, OPTION_H_STR))
    return (OPTION_H);
  else if (!strcmp(arg, OPTION_J_STR))
    return (OPTION_J);
  else
    return (0);
}

t_options	init_options_structure()
{
  t_options	init_options;

  init_options.fd = -1;
  init_options.json =
    init_options.help =
    init_options.reaction =
    init_options.noarg =
    init_options.help_afterarg =
    !(init_options.correct = true);
  init_options.id = init_options.invalidarg = NULL;
  return (init_options);
}

t_options	parse_options_aux(char **av, t_options options_ret, int counter)
{
  while (av[counter] && options_ret.correct)
    {
      if ((get_option(av[counter]) == OPTION_I) && av[counter + 1])
	{
	  if (!options_ret.reaction)
	    {
	      counter++;
	      options_ret.id = av[counter];
	      if (av[counter + 1] &&
		  (options_ret.reaction = (get_option(av[counter + 1]) == OPTION_E)))
		  counter++;
	    }
	}
      else if ((options_ret.json = (get_option(av[counter]) == OPTION_J)));
      else if (get_option(av[counter]) != OPTION_J &&
	       get_option(av[counter]) != OPTION_E &&
	       get_option(av[counter]) != OPTION_I)
	{
	  options_ret.correct = false;
	  options_ret.help_afterarg = (get_option(av[counter]) == OPTION_H);
	  options_ret.invalidarg = av[counter];
	}
      counter++;
    }
  return (options_ret);
}

t_options	parse_options(char **av)
{
  t_options	options_ret;

  options_ret = init_options_structure();
  if (av[0])
    {
      if (!(options_ret.help = (get_option(av[0]) == OPTION_H)))
	options_ret.correct = !((options_ret.fd = open(av[0], O_RDONLY)) < 0);
    }
  else
    options_ret.noarg = !(options_ret.correct = false);
  if (!options_ret.help && !options_ret.noarg && options_ret.correct)
    options_ret = parse_options_aux(&av[1], options_ret, 0);
  return (options_ret);
}
