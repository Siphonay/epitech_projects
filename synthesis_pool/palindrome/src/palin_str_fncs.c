/*
** palin_str_fncs.c for palindrome in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jun 18 09:42:03 2016 Alexis Viguié
** Last update Sat Jun 18 15:05:50 2016 Alexis Viguié
*/

#include <string.h>
#include <stdlib.h>

char	*palin_revstr(char *str)
{
  char	*rev_str;
  int	counter;
  int	counter2;

  counter = strlen(str);
  if (!(rev_str = calloc(counter + 1, sizeof(char))))
    return (NULL);
  counter--;
  counter2 = 0;
  while (counter >= 0)
    {
      rev_str[counter2] = str[counter];
      counter2++;
      counter--;
    }
  return (rev_str);
}

int	is_a_palindrome(char *str)
{
  char	*rev_str;
  int	ret_val;

  if (!(rev_str = palin_revstr(str)))
    return (-1);
  if (!strcmp(str, rev_str))
    ret_val = 1;
  else
    ret_val = 0;
  free(rev_str);
  return (ret_val);
}

char	*int_to_base_str(int nb, char *base)
{
  int	counter;
  int	numlen;
  int	op_num;
  char	*str_ret;

  op_num = nb;
  numlen = counter = 0;
  while (nb)
    {
      numlen++;
      nb /= strlen(base);
    }
  if (!(str_ret = calloc(strlen(base) + 100, sizeof(char))))
    return (NULL);
  while (counter < numlen)
    {
      str_ret[numlen - (counter + 1)] = base[op_num % strlen(base)];
      op_num /= strlen(base);
      counter++;
    }
  return (str_ret);
}
