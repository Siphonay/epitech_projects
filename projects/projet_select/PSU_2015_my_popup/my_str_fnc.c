/*
** my_str_fnc.c for my popup in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Nov 30 14:15:05 2015 Alexis Viguié
** Last update Mon Nov 30 15:24:58 2015 Alexis Viguié
*/

#include <unistd.h>

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

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}
