/*
** div.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m/ex04
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 16:29:33 2017 Alexis Viguié
** Last update Thu Jan  5 17:35:00 2017 Alexis Viguié
*/

#include "castmania.h"

int	integer_div(int a, int b)
{
  if (!b)
    return (b);
  return (a / b);
}

float	decimale_div(int a, int b)
{
  if (!b)
    return (b);
  return ((float)a / b);
}

void		exec_div(t_div *operation)
{
  t_integer_op	*int_op;
  t_decimale_op	*dec_op;
  
  if (operation->div_type == INTEGER)
    {
      int_op = (t_integer_op *)operation->div_op;
    int_op->res = integer_div(int_op->a, int_op->b);
    }
  else
    {
      dec_op = (t_decimale_op *)operation->div_op;
      dec_op->res = decimale_div(dec_op->a, dec_op->b);
    }
}
