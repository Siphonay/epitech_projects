/*
** my_putstr.c for tree in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Apr 26 14:38:31 2016 Alexis Viguié
** Last update Tue Apr 26 17:58:29 2016 Simon Pedrono
*/

#include <unistd.h>

void		my_putstr(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

void		my_putchar_err(char c)
{
  write(2, &c, 1);
}

void		my_putstr_err(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    {
      write(2, &str[counter], 1);
      counter++;
    }
}
