/*
** main.c for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 09:55:13 2016 Alexis Viguié
** Last update Sat Jan  9 19:43:12 2016 Alexis Viguié
*/

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "tek_arc.h"

int	main(int ac, char **av)
{
  int	file_counter;
  FILE	**file_list;

  if (ac < 3)
    exit_usage(av[0]);
  if ((file_list = malloc(sizeof(FILE) * (ac - 2))) == NULL)
    exit_mllc();
  file_counter = 2;
  while (file_counter < ac)
    {
      if ((file_list[file_counter - 2] = fopen(av[file_counter], "r")) == NULL)
	exit_file_error(file_list, av[file_counter]);
      file_counter++;
    }
  create_arc(file_list, av, ac - 2);
  close_flist(file_list, ac - 2);
  return (0);
}
