/*
** sub_inf.c for bistro in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Oct 27 12:38:33 2015 Alexis Viguié
** Last update Wed Oct 28 14:43:03 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "subinf.h"
#include "bistro_ops.h"

char	*sub_func(char *arg1, char *arg2)
{
  char	*num1;
  char	*num2;
  int	len1;
  int	len2;
  int	counter;
  int	counter2;
  int	remainder;
  char	*res;
  char	*ret_res;

  len1 = my_strlen(arg1);
  len2 = my_strlen(arg2);
  if (len1 > len2)
    {
      num1 = my_revstr(arg1);
      num2 = small_instring(len1, my_revstr(arg2));
    }
  else if (len1 < len2)
    {
      my_putchar('-');
      num1 = my_revstr(arg2);
      num2 = small_instring(len2, my_revstr(arg1));
    }
  else
    {
      counter = 0;
      while((arg1[counter] == arg2[counter]) && arg1[counter] != '\0')
	  counter++;
      if (arg1[counter] > arg2[counter])
	{
	  num1 = my_revstr(arg1);
	  num2 = my_revstr(arg2);
	}
      else if (arg1[counter] < arg2[counter])
	{
	  my_putchar('-');
	  num1 = my_revstr(arg2);
	  num2 = my_revstr(arg1);
	}
      else
	{
	  return ("0");
	}
    }
  res = malloc(my_strlen(num1) * sizeof(char) + 1);
  counter = 0;
  remainder = 0;
  while (num1[counter] != '\0' && num2[counter] != '\0')
    {
      res[counter] = (num1[counter] - '0') - (remainder + num2[counter] - '0');
      if (res[counter] < 0)
	{
	  res[counter] = res[counter] + 10;
	  remainder = 1;
	}
      else
	remainder = 0;
      res[counter] = res[counter] + '0';
      counter++;
    }
  res[counter] = '\0';
  res = my_revstr(res);
  counter = 0;
  while (res[counter] == '0')
    counter++;
  ret_res = malloc((my_strlen(res) - counter) * sizeof(char) + 1);
  counter2 = 0;
  while (res[counter] != '\0')
    {
      ret_res[counter2] = res[counter];
      counter++;
      counter2++;
    }
  ret_res[counter2] = '\0';
  return(ret_res);
}
