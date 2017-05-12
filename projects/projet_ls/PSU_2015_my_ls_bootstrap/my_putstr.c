/*
** my_putstr.c for ls bootstrap in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Nov 16 11:06:44 2015 Alexis Viguié
** Last update Mon Nov 16 11:07:19 2015 Alexis Viguié
*/

#include <unistd.h>

void	my_putstr_err(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      write(2, &str[counter], 1);
      counter++;
    }
}

void	my_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != 0)
    {
      write(1, &str[counter], 1);
      counter++;
    }
}
