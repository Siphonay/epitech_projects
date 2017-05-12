/*
** add_inf.c for bistro in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Oct 26 12:02:55 2015 Alexis Viguié
** Last update Wed Oct 28 14:42:42 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "addinf.h"
#include "bistro_ops.h"

char	*process_remainder(char *res, int counter)
{
  res[counter] = '1';
  res[counter + 1] = '\0';
  return (res);
}

char	*add_inf(char *num1, char *num2)
{
  int	counter;
  int	remainder;
  char	*res;

  counter = 0;
  remainder = 0;
  res = malloc(my_strlen(num1) * sizeof(char) + 2);
  if (res == NULL)
    return (res);
  while (num1[counter] != '\0')
    {
      res[counter] = remainder + (num1[counter] - '0') + (num2[counter] - '0');
      if (res[counter] > 9)
	remainder = 1;
      else
	remainder = 0;
      res[counter] = res[counter] - remainder * 10 + '0';
      counter++;
    }
  if (remainder)
    {
      res = process_remainder(res, counter);
    }
  else
    res[counter] = '\0';
  return (res);
}

char	*add_func(char *arg1, char *arg2)
{
  char	*num1;
  char	*num2;
  char	*res;
  int	len1;
  int	len2;

  len1 = my_strlen(arg1);
  len2 = my_strlen(arg2);

  if (len1 > len2)
    {
      num1 = arg1;
      num2 = small_instring(len1, arg2);
      if (num2 == NULL)
	return (num2);
    }
  else if (len1 < len2)
    {
      num1 = arg2;
      num2 = small_instring(len2, arg1);
      if (num2 == NULL)
	return (num2);
    }
  else
    {
      num1 = arg1;
      num2 = arg2;
    }
  return (my_revstr(add_inf(num1, num2)));
}
