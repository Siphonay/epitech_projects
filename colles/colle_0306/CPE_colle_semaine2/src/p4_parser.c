/*
** p4_parser.c for colle2 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May  3 14:30:21 2016 Alexis Viguié
** Last update Tue May  3 17:14:05 2016 Alexis Viguié
*/

#include "p4.h"
#include "my.h"

void	ops_setdefaults(t_p4_opts *options)
{
  options->width = DEFOPS_W;
  options->height = DEFOPS_H;
  options->p1_avatar = DEFOPS_P1;
  options->p2_avatar = DEFOPS_P2;
  options->a_avatar = DEFOPS_A;
  options->ia = DEFOPS_IA;
}

int	p4_parse_options(char **args, t_p4_opts *options)
{
  int	counter;

  ops_setdefaults(options);
  counter = 1;
  while (args[counter])
    {
      options->ia = my_strcmp(args[counter], OP_IA);
      if (my_strcmp(args[counter], OP_W))
	{
	  if ((options->width = my_get_nbr(args[++counter])) == -1)
	    return (err_bad_param(args[counter], args[counter - 1], options));
	}
      else if (my_strcmp(args[counter], OP_H))
	{
	  if ((options->height = my_get_nbr(args[++counter])) == -1)
	    return (err_bad_param(args[counter], args[counter - 1], options));
	}
      else if (!my_strcmp(args[counter], OP_IA))
	return (err_usage(args[counter], args[0], options));
      counter++;
    }
  return (check_parser_errors(options));
}
