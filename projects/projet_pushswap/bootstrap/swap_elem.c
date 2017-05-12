/*
** swap_elem.c for swap elem in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Nov  3 17:11:05 2015 Alexis Viguié
** Last update Tue Nov  3 17:17:18 2015 Alexis Viguié
*/

void	swap_elem(int *array, int index1, int index2)
{
  int	swap_container;

  swap_container = array[index1];
  array[index1] = array[index2];
  array[index2] = swap_container;
}
