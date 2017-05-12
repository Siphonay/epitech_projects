/*
** scrabble_functions.c for my scrabble in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov 26 17:03:20 2015 Alexis Viguié
** Last update Thu Nov 26 17:05:25 2015 Alexis Viguié
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}

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

int	my_get_nbr(char *str)
{
  int	counter;
  int	res;
  int	neg;

  counter = 0;
  res = 0;
  neg = 1;
  while ((str[counter] < '0' || str[counter] > '9') && str[counter])
    counter++;
  if (counter > 0 && str[counter - 1] == '-')
      neg = -1;
  while (str[counter] >= '0' && str[counter] <= '9')
    {
      res = res * 10 + str[counter] - '0';
      counter++;
    }
  return (res * neg);
}
