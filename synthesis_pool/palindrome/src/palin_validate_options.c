/*
** palin_validate_options.c for palindrome in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Jun 17 15:00:55 2016 Alexis Viguié
** Last update Sat Jun 18 16:54:01 2016 Alexis Viguié
*/

#include <stdio.h>
#include "palin.h"

bool	palin_validate_options(t_options options)
{
  bool	ret_val;

  ret_val = true;
  if (options.invalid_arg)
    {
      ret_val = false;
      fprintf(stderr, ERR_INVALID_ARG);
    }
  else if (!options.num && !options.pal && !options.help)
    {
      ret_val = false;
      fprintf(stderr, ERR_NOARG);
    }
  else if ((options.num && options.pal) || (options.imax < options.imin))
    {
      ret_val = false;
      fprintf(stderr, ERR_INCOMPATIBLE_ARG);
    }
  else if (options.base < BASE_MIN || options.base > BASE_MAX ||
			 options.imin < 0 || options.imax < 0)
    {
      ret_val = false;
      fprintf(stderr, ERR_OOB);
    }
  return (ret_val);
}
