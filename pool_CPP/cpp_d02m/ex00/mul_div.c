/*
** mul_div.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 09:28:44 2017 Alexis Viguié
** Last update Thu Jan  5 09:32:40 2017 Alexis Viguié
*/

void	add_mul_4param(int first, int second, int *add, int *mul)
{
  *add = first + second;
  *mul = first * second;
}

void	add_mul_2param(int *first, int *second)
{
  int	first_stock;
  int	second_stock;

  first_stock = *first;
  second_stock = *second;
  *first = first_stock + second_stock;
  *second = first_stock * second_stock;
}
