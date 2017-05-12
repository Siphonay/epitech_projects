/*
** mem_ptr.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m/ex01
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 09:54:52 2017 Alexis Viguié
** Last update Thu Jan  5 10:17:20 2017 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"

void	add_str(char *str1, char *str2, char **res)
{
  int	counter;
  char	*res_str;
  
  if (!(res_str = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char))))
    exit(84);
  counter = 0;
  while (str1[counter])
    {
      res_str[counter] = str1[counter];
      counter++;
    }
  counter = 0;
  while (str2[counter])
    {
      res_str[strlen(str1) + counter] = str2[counter];
      counter++;
    }
  res_str[strlen(str1) + counter] = 0;
  *res = res_str;
}

void	add_str_struct(t_str_op *str_op)
{
  int	counter;
  
  if (!(str_op->res = malloc((strlen(str_op->str1) + strlen(str_op->str2) + 1) * sizeof(char))))
    exit(84);
  counter = 0;
  while (str_op->str1[counter])
    {
      str_op->res[counter] = str_op->str1[counter];
      counter++;
    }
  counter = 0;
  while (str_op->str2[counter])
    {
      str_op->res[strlen(str_op->str1) + counter] = str_op->str2[counter];
      counter++;
    }
  str_op->res[strlen(str_op->str1) + counter] = 0;
}
