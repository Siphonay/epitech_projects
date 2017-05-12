/*
** main.c for fakeProj in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 27 15:36:26 2016 Alexis Viguié
** Last update Mon Jun 27 15:48:25 2016 Alexis Viguié
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fakeProj.h"
#include "calc/calc.h"

int	main(int ac, char **av)
{
  t_ops	ops[CHAR_MAX];
  t_ops	op;

  if (ac < 4 || !memset(ops, 0, CHAR_MAX))
    return (FAKE_EXIT_FAILURE);
  ops[ADD_CHAR] = op_add;
  ops[SUB_CHAR] = op_sub;
  ops[MUL_CHAR] = op_mul;
  ops[DIV_CHAR] = op_div;
  ops[MOD_CHAR] = op_mod;
  op = ops[(int)av[2][0]];
  if (op)
    printf(PRINTF_STR, op(atoi(av[1]), atoi(av[3])));
  return (FAKE_EXIT_SUCCESS);
}
