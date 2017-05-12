/*
** tetris_pustr.c for putstr in /home/guillaume/Bureau/code/tp/unix/PSU_2015_tetris/src
**
** Made by Guillaume Morin
** Login   <guillaume@epitech.net>
**
** Started on  Tue Feb 23 15:55:46 2016 Guillaume Morin
** Last update Tue Mar  1 17:13:07 2016 Guillaume Morin
*/

#include <unistd.h>
#include "tetris_lib.h"

void		tetris_putstr(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}
