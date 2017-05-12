/*
** castmania.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m/ex04
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 16:45:47 2017 Alexis Viguié
** Last update Thu Jan  5 17:49:48 2017 Alexis Viguié
*/

#include <stdio.h>
#include "castmania.h"

void		exec_operation(t_instruction_type instruction_type, void *data)
{
  t_instruction	*instr;
  t_add		*addt_op;
  t_div		*divi_op;
  t_decimale_op	*deci_divi;
  t_integer_op	*integ_divi;

  instr = (t_instruction *)data;
  if (instruction_type == ADD_OPERATION)
    {
      addt_op = (t_add *)instr->operation;
      exec_add(addt_op);
      if (instr->output_type == VERBOSE)
	printf("%i\n", addt_op->add_op.res);
    }
  else
    {
      divi_op = (t_div *)instr->operation;
      exec_div(divi_op);
      if (instr->output_type == VERBOSE)
	{
	  if (divi_op->div_type == DECIMALE)
	    {
	      deci_divi = (t_decimale_op *)divi_op->div_op;
	      printf("%f\n", deci_divi->res);
	    }
	  else
	    {
	      integ_divi = (t_integer_op *)divi_op->div_op;
	      printf("%i\n", integ_divi->res);
	    }
	}
    }
}

void	exec_instruction(t_instruction_type instruction_type, void *data)
{
  int	*i;
  float	*j;
  
  if (instruction_type == PRINT_INT)
    {
      i = (int *)data;
      printf("%i\n", *i);
    }
  else if (instruction_type == PRINT_FLOAT)
    {
      j = (float *)data;
      printf("%f\n", *j);
    }
  else
    exec_operation(instruction_type, data);
}
