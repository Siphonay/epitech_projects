/*
** do_op.c for 42sh in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May 31 15:40:46 2016 Alexis Viguié
** Last update Sat Jun  4 19:01:44 2016 Alexis Viguié
*/

#include <stdbool.h>
#include <string.h>
#include "exit_doop.h"
#include "mysh.h"

bool	my_isalpha(char	*str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      if (str[counter] < '0' || str[counter] > '9')
	return (false);
      counter++;
    }
  return (true);
}

t_exitval	aux_doop(char **ops, int counter, t_exitval ret_struct)
{
  if (!ops[counter + 1] || !my_isalpha(ops[counter + 1]))
    ret_struct.is_valid = false;
  else if (!strcmp(ops[counter], OP_PLUS))
    ret_struct.value += my_getnbr(ops[counter + 1]);
  else if (!strcmp(ops[counter], OP_MINUS))
    ret_struct.value -= my_getnbr(ops[counter + 1]);
  else if (!strcmp(ops[counter], OP_TIMES))
    ret_struct.value *= my_getnbr(ops[counter + 1]);
  else if (!strcmp(ops[counter], OP_DIVIDE))
    ret_struct.value /= my_getnbr(ops[counter + 1]);
  else if (!strcmp(ops[counter], OP_MODULO))
    ret_struct.value %= my_getnbr(ops[counter + 1]);
  else
    ret_struct.is_valid = false;
  return (ret_struct);
}

t_exitval	exit_doop(char **ops)
{
  t_exitval	ret_struct;
  int		counter;

  ret_struct.is_valid = true;
  if (!my_isalpha(ops[0]))
    ret_struct.is_valid = false;
  else
    ret_struct.value = my_getnbr(ops[0]);
  counter = 1;
  while (ops[counter] && ret_struct.is_valid)
    {
      ret_struct = aux_doop(ops, counter, ret_struct);
      counter += 2;
    }
  return (ret_struct);
}
