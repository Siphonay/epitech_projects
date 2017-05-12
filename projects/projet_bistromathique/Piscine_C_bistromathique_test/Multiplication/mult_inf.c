/*
** mult_inf.c for mult_inf in /home/coutar_b/rendu/Piscine_C_bistromathique/Piscine_C_bistromathique_test/Multiplication
**
** Made by Thomas Coutard
** Login   <coutar_b@epitech.net>
**
** Started on  Tue Oct 27 20:10:04 2015 Thomas Coutard
** Last update Wed Oct 28 17:31:23 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "multinf.h"
#include "addinf.h"
#include "bistro_ops.h"

char	process_remmult(char *res, int counter)
{
  char	remmult;

  remmult = res[counter] / 10;
  return (remmult);
}

char	*mult_inf(char *num1, char *num2)
{
  int	counter;
  int	counter2;
  int	remmult;
  char	*res_mult;
  char	*res;

  counter = 0;
  res_mult = malloc((my_strlen(num1) + my_strlen(num2) * sizeof(char) + 2));
  res = malloc((my_strlen(num1) + my_strlen(num2) * sizeof(char) + 2));
  remmult = 0;
  res[0] = '\0';
  if (res == NULL)
    return (res);
  while (num2[counter] != '\0')
    {
      counter2 = 0;
      while (num1[counter2] != '\0')
	{
	  res_mult[counter2] = (num2[counter] - '0') * (num1[counter2] - '0' + remmult);
	  if (res_mult[counter2] > 9)
	    {
	      remmult = process_remmult(res_mult, counter2);
	      res_mult[counter2] = (res_mult[counter2] % (remmult * 10));
	    }
	  else
	    {
	      remmult = 0;
	    }
	  res_mult[counter2] = res_mult[counter2] + '0';
	  counter2++;
	}
      res_mult[counter2] = '\0';
      res = my_revstr(add_func(res_mult, res));
      counter++;
    }
  return (res);
}
char	*mult_func(char *arg1, char *arg2)
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
  return(my_revstr(mult_inf(my_revstr(num1), my_revstr(num2))));
}
