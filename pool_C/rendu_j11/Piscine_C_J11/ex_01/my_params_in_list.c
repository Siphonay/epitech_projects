/*
** my_params_in_list.c for my params in list in /home/viguie_a/rendu_j11/Piscine_C_J11
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct 12 11:41:23 2015 Alexis Viguié
** Last update Mon Oct 12 16:06:14 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "mylist.h"

t_list		*my_params_in_list(int ac, char **av)
{
  t_list	*list;
  int		counter;

  counter = 0;
  list = NULL;
  while (counter < ac)
    {
      my_put_in_list(&list, av[counter]);
      counter++;
    }
  return (list);
}
