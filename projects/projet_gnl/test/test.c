/*
** test.c for test in /home/sam/Rendu/Projets/projet_gnl/test
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan 16 21:57:37 2016 Alexis Viguié
** Last update Sat Jan 16 22:00:30 2016 Alexis Viguié
*/

#include <stdio.h>

int	main(int ac, char **av)
{
  char	*test;

  if (ac != 2)
    return (1);
  test = NULL;
  printf("%i\n", (test == NULL));
  test = av[1];
  printf("%i\n", ((test != NULL) + 1));
  return (0);
}
