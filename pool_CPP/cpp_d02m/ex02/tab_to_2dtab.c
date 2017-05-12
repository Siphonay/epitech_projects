/*
** tab_to_2dtab.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m/ex02
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 10:37:19 2017 Alexis Viguié
** Last update Thu Jan  5 15:10:11 2017 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int	**tab_res;
  int	counter;
  int	l_counter;
  int	w_counter;

  if (!(tab_res = malloc((length + 1) * sizeof(int*))))
    exit(84);
  tab_res[length] = NULL;
  counter = 0;
  while (counter < length)
    {
      if (!(tab_res[counter] = malloc((width + 1) * sizeof(int))))
	exit(84);
      memset(tab_res[counter], 0, length);
      counter++;
    }
  counter = l_counter = w_counter = 0;
  while (l_counter < length)
    {
      tab_res[l_counter][w_counter] = tab[counter];
      counter++;
      w_counter++;
      if (w_counter == width)
	{
	  l_counter++;
	  w_counter = 0;
	}
    }
  if (l_counter < length)
    {
      tab_res[l_counter + 1] = NULL;
      memset(&tab_res[l_counter][w_counter], 0, width - w_counter);
    }
  *res = tab_res;
}
