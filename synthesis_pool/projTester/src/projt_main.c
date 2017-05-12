/*
** projt_main.c for projTester in /home/sam/Rendu/Piscine_S/projTester
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jun 25 10:17:42 2016 Alexis Viguié
** Last update Sat Jun 25 10:45:21 2016 Alexis Viguié
*/

#include "projt.h"

int	main(int ac, char **av)
{
  if (ac < 2)
    return (PROJT_EXIT_FAILURE);
  return (projt_trd(av[1], 0));
}
