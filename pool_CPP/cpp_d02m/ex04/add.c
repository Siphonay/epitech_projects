/*
** add.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m/ex04
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 16:39:25 2017 Alexis Viguié
** Last update Thu Jan  5 17:26:16 2017 Alexis Viguié
*/

#include <stdlib.h>
#include "castmania.h"

int	normal_add(int a, int b)
{
  return (a + b);
}

int	absolute_add(int a, int b)
{
  return (abs(a) + abs(b));
}

void	exec_add(t_add *operation)
{
  if (operation->add_type == NORMAL)
    operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
  else
    operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}
