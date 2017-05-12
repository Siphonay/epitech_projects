/*
** sam_int_to_bin.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Mon Feb 15 17:24:03 2016 Alexis Viguié
** Last update Mon Feb 15 17:48:23 2016 Alexis Viguié
*/

#include <stdlib.h>

char		*sam_int_to_bin(int nb)
{
  unsigned int	counter;
  unsigned int	ret_len;
  unsigned int	op_num;
  char		*ret_str;

  op_num = nb;
  ret_len = (counter = 0);

  while (nb)
    {
      ret_len++;
      nb /= 2;
    }
  if ((ret_str = malloc(sizeof(char) * (ret_len + 1))) == NULL)
    return (NULL);
  ret_str[ret_len] = '\0';
  while (counter < ret_len)
    {
      ret_str[ret_len - (counter + 1)] = (op_num % 2 + '0');
      op_num /= 2;
      counter++;
    }
  return (ret_str);
}
