/*
** p4_error.c for colle2 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May  3 15:04:59 2016 Alexis Viguié
** Last update Tue May  3 17:16:45 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "p4.h"
#include "my.h"

int	err_usage(const char *invalid_param, const char *bin_name,
		  t_p4_opts *options)
{
  my_putstr_err("'");
  my_putstr_err(invalid_param);
  my_putstr_err("': invalid parameter\n");
  my_putstr_err("usage: ");
  my_putstr_err(bin_name);
  my_putstr_err(" [-w WIDTH -h HEIGHT -p1 AVATAR -p2 AVATAR -a AVATAR -ia]\n");
  free(options);
  return (1);
}

int	err_bad_param(const char *invalid_val, const char *param_name,
		      t_p4_opts *options)
{
  my_putstr_err("'");
  if (invalid_val)
    my_putstr_err(invalid_val);
  my_putstr_err("' invalid value for parameter '");
  my_putstr_err(param_name);
  my_putstr_err("'\n");
  free(options);
  return (1);
}

bool	check_parser_errors(t_p4_opts *options)
{
  bool	error;

  error = false;
  if ((error = options->width * options->height < 20))
    my_putstr_err("grid is too small: it must have at least 20 cases.\n");
  else if ((error = options->width > 80))
    my_putstr_err("width cannot exceet 80.\n");
  else if ((error = options->height > 16))
    my_putstr_err("height cannot exceed 16.\n");
  else if ((error = (options->p1_avatar == options->p2_avatar ||
		options->p1_avatar == options->a_avatar ||
		options->p2_avatar == options->a_avatar)))
    my_putstr_err("conflict in avatars, check that they are all different.\n");
  return (error);
}
