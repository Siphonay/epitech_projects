/*
** my_putstr.c for my poker in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Dec 10 14:05:34 2015 Alexis Viguié
** Last update Thu Dec 10 14:07:14 2015 Alexis Viguié
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

void	my_putstr_err(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(2, &str[counter], 1);
      counter++;
    }
}
