/*
** my_strlen.c for strlen in /home/merlin/rendu/CPE/CPE_2015_corewar
**
** Made by Victor Herlin
** Login   <merlin@epitech.net>
**
** Started on  Fri Mar 25 15:54:00 2016 Victor Herlin
** Last update Fri Mar 25 15:54:35 2016 Victor Herlin
*/

#include <asm.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
