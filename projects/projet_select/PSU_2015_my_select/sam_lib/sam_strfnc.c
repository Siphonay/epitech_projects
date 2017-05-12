/*
** sam_strfnc.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec  4 14:32:24 2015 Alexis Viguié
** Last update Sun Dec 13 22:23:01 2015 Alexis Viguié
*/

#include <unistd.h>

int	sam_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}

void	sam_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

void	sam_putstr_err(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(2, &str[counter], 1);
      counter++;
    }
}
