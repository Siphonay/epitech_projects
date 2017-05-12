/*
** palin_sarah.c for palindrome in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Jun 17 15:35:55 2016 Alexis Viguié
** Last update Sat Jun 18 16:58:01 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "palin.h"

char	*get_base(int base)
{
  char	*ret_base;

  if (!(ret_base = calloc(base + 1, sizeof(char))))
      return (NULL);
  if (!(ret_base = strncat(ret_base, BASE_TEN, base)))
    return (NULL);
  return (ret_base);
}

int	palindrome_operation(int nb)
{
  char	*tmp;
  char	*tmp2;

  if (!(tmp = int_to_base_str(nb, BASE_TEN)) || !(tmp2 = palin_revstr(tmp)))
    return (-1);
  nb += atoi(tmp2);
  free(tmp);
  free(tmp2);
  return (nb);
}

int	palin_find_pal(t_options options, char *base)
{
  int	cntr;
  int	cntr2;
  int	nb;
  bool	palindrome_found;
  char	*tmp;
  char	*tmp2;

  cntr = palindrome_found = 0;
  while ((nb = cntr) <= options.value)
    {
      cntr2 = 0;
      while (cntr2 <= options.imax && nb >= cntr)
	{
	  if (!(tmp = int_to_base_str(nb, base)) ||
	      !(tmp2 = int_to_base_str(options.value, base)))
	    return (PALIN_EXIT_FAILURE);
	  if (cntr2 >= options.imin && !strcmp(tmp, tmp2))
	    palindrome_found = aux_print_palindrome(options, cntr, cntr2);
	  nb = palindrome_operation(nb);
	  cntr2 = aux_free(tmp, tmp2, cntr2);
	}
      cntr++;
    }
  aux_nosolution(palindrome_found);
  return (PALIN_EXIT_SUCCESS);
}

int	palin_find_num(t_options options, char *base)
{
  int	cntr;
  int	nb;
  bool	palindrome_found;
  char	*tmp;

  cntr = palindrome_found = 0;
  nb = options.value;
  while (cntr <= options.imax && nb >= options.value)
    {
      if (cntr >= options.imin)
	{
	  if (!(tmp = int_to_base_str(nb, base)))
	    return (PALIN_EXIT_FAILURE);
	  if (is_a_palindrome(tmp) > 0)
	    palindrome_found = aux_print_number(options, nb, cntr);
	  free(tmp);
	}
      nb = palindrome_operation(nb);
      cntr++;
    }
  aux_nosolution(palindrome_found);
  return (PALIN_EXIT_SUCCESS);
}

int	palin_sarah(t_options options)
{
  char	*num_base;
  char	store_num[48];
  int	ret_val;

  if (!(num_base = get_base(options.base)))
    return (PALIN_EXIT_FAILURE);
  if (options.num)
    ret_val = palin_find_num(options, num_base);
  if (options.pal)
    {
      sprintf(store_num, "%i", options.value);
      if (!is_a_palindrome(store_num))
	return (PALIN_EXIT_FAILURE);
      ret_val = palin_find_pal(options, num_base);
    }
  free(num_base);
  return (ret_val);
}
