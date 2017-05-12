/*
** main.c for Colle2 in /home/joly_r/rendu/Colles/Colle2/Colle2/src
**
** Made by joly_r
** Login   <joly_r@epitech.net>
**
** Started on  Tue May  3 14:20:54 2016 joly_r
** Last update Tue May  3 17:37:46 2016 Alexis Viguié
*/

#include <unistd.h>
#include <stdbool.h>

void	my_putchar(char a)
{
  write(1, &a, 1);
}

size_t     my_strlen(const char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      write(1, &str[i], 1);
      i++;
    }
}

void	my_putstr_err(const char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

int	my_get_nbr(const char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      res += str[i] - '0';
      i++;
      res *= 10;
    }
  res /= 10;
  return (res);
}
