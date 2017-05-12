/*
** my_putstr.c for my transformer in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 09:19:25 2015 Alexis Viguié
** Last update Fri Dec 18 10:25:56 2015 Alexis Viguié
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
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
