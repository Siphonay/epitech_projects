/*
** my_putchar.c for CPE_colle_semaine1 in /home/simon/CPE_colle_semaine1/lib
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 16:07:22 2016 Simon Pedrono
** Last update Tue Apr 26 17:58:35 2016 Simon Pedrono
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
