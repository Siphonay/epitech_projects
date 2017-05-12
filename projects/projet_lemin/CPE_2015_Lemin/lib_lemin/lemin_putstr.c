/*
** lemin_putstr.c for lib lemin in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Apr 14 14:37:05 2016 Alexis Viguié
** Last update Thu Apr 14 14:38:47 2016 Alexis Viguié
*/

#include <unistd.h>

void		lemin_putstr(char *str, int fd)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    {
      write(fd, &str[counter], 1);
      counter++;
    }
}
