/*
** sam_putstr.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Feb  8 17:07:59 2016 Alexis Viguié
** Last update Mon Feb  8 17:09:24 2016 Alexis Viguié
*/

#include <unistd.h>

void		sam_putstr(char *str, int fd)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    {
      write(fd, &str[counter], 1);
      counter++;
    }
}
