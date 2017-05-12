/*
** my_strerr.c for colle 3 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Oct 25 02:25:39 2015 Alexis Viguié
** Last update Sun Oct 25 02:39:06 2015 Alexis Viguié
*/

#include <unistd.h>

int	my_strerr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    {
      write(2, &str[counter], 1);
      counter++;
    }
  return (0);
}
