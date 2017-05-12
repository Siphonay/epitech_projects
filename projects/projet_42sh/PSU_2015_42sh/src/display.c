/*
** display.c for PSU_2015_42sh
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Sun Jun 05 11:22:18 2016 pedron_s
** Last update	Sun Jun 05 18:01:16 2016 pedron_s
*/

#include <unistd.h>
#include "mysh.h"

void	my_putchar(char c)
{
  write(STDOUT_FILENO, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
