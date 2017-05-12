/*
** read_cocktail.c for colle cocktail in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Dec  2 14:24:26 2015 Alexis Viguié
** Last update Wed Dec  2 15:42:18 2015 Alexis Viguié
*/

#include <stdlib.h>

int	my_isnum(char c)
{
  if ((c >= '0' && c <= '9') || c == '-')
    return (1);
  else
    return (0);
}

int	verif_string(char *drink_input)
{
  int	num_place;
  int	counter;

  counter = 0;
  num_place = 0;
  while (my_isnum(drink_input[counter]))
    {
      num_place = 1;
      counter++;
    }
  if (!num_place)
    return (1);
  if (drink_input[counter] == ' ')
    counter++;
  else
    return (1);
  while (drink_input[counter] == ' ')
    counter++;
  if (drink_input[counter] == '\n')
    return (1);
  else
    return (0);
}

char	*get_cocktail(char *d_input)
{
  char	*str_ret;
  char	*tmp_str;
  int	cntr;
  int	cntr2;

  cntr = 0;
  tmp_str = d_input;

  while (d_input[cntr] == ' ' && d_input[cntr] != '\n' && my_isnum(*d_input))
    cntr++;
  if (d_input[cntr] == '\n')
    return ("\0");
  else
    {
      cntr2 = 0;
      while (cntr2 < cntr && ++tmp_str && ++cntr2);
      while (*tmp_str != '\n' && ++cntr2 && ++tmp_str);
      if ((str_ret = malloc((cntr2 - cntr + 1) * sizeof(char))) == NULL)
	exit (1);
      str_ret[cntr2 - cntr] = '\0';
      tmp_str -= cntr2;
      cntr = 0;
      while (*tmp_str != '\n' && (str_ret[cntr] = *tmp_str) && ++tmp_str);
    }
  return (str_ret);
}
