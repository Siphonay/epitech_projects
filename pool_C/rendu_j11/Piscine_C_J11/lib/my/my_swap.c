/*
** my_swap.c for my swap in /home/viguie_a/rendu_j04
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Thu Oct  1 14:00:42 2015 Alexis Viguié
** Last update Tue Oct  6 14:01:31 2015 Alexis Viguié
*/

int	my_swap(int *a, int *b)
{
  int	swapper;

  swapper = *a;
  *a = *b;
  *b = swapper;
}
