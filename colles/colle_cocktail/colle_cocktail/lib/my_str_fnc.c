/*
** my_str_fnc.c for colle cocktail in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Dec  2 14:15:16 2015 Alexis Viguié
** Last update Wed Dec  2 14:17:31 2015 Alexis Viguié
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
