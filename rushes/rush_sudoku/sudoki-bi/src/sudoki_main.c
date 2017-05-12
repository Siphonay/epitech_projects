/*
** sudoki_main.c for sudoki bi in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Sat Feb 27 09:57:01 2016 Alexis Viguié
** Last update Sat Feb 27 17:35:29 2016 Alexis Viguié
*/

#include <unistd.h>
#include "sudoki.h"

int		main()
{
  unsigned char	***sudoki_table;
  unsigned int	counter;

  if ((sudoki_table = sudoki_parse()) == NULL)
    return (1);
  counter = 0;
  while (sudoki_table[counter])
    {
      sudoki_table[counter] = sudoki_algo(sudoki_table[counter]);
      counter++;
    }
  sudoki_disp(sudoki_table);
  sudoki_free(sudoki_table);
  return (0);
}
