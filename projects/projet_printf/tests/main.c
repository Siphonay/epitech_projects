/*
** main.c for main test in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov  5 16:43:43 2015 Alexis Viguié
** Last update Thu Nov  5 17:07:57 2015 Alexis Viguié
*/

#include "my.h"

int	main()
{
  if (sum_stdarg(0, 3, 1, 2, 3) == 6)
    my_putstr("TEST 1 OK!\n");
  else
    my_putstr("TEST 1 FAILED!\n");
  if (sum_stdarg(1, 5, "Bonjour", "a", "toto", "", "plop") == 16)
      my_putstr("TEST 2 OK!\n");
  else
      my_putstr("TEST 2 FAILED!\n");
  if (!(disp_stdarg("csiis", 'X', "coucou", 10, -3, "plop")))
    my_putstr("TEST 3 OK!\n");
  else
    my_putstr("TEST 3 FAILED!\n");
  return (0);
}
