/*
** main.c for main in /home/ruffetm/rendu/RUSH/marvin_ruffet_m/srcs
**
** Made by Mathieu RUFFET
** Login   <ruffetm@epitech.net>
**
** Started on  Sat May 14 09:57:16 2016 Mathieu RUFFET
** Last update Sat May 14 16:50:03 2016 Alexis Viguié
*/

#include <stdio.h>
#include "marvin.h"

int	main(int ac, char **av)
{
  if (ac != 2)
    {
      printf("\n");
      return (EXIT_FAILURE);
    }
  if (is_var(av[1]))
    disp_var(my_str_to_wordtab(av[1]));
  else
    printf("not yet implemented\n");
  return (EXIT_SUCCESS);
}
