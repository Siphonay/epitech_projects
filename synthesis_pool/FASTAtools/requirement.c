/*
** requirement.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 09:19:15 2016 Alexis Viguié
** Last update Mon Jun 20 09:44:25 2016 Alexis Viguié
*/

#include <stdbool.h>

bool	char_isalpha(char c)
{
  return ((c >= 'A' && c <= 'Z') ||
	  (c >= 'a' && c <= 'z') ||
	  (c >= '0' && c <= '9'));
}

char	*my_strcapitalize_synthesis(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      if ((!counter || (counter && !char_isalpha(str[counter - 1]))) &&
	  (str[counter] >= 'a' && str[counter] <= 'z'))
	str[counter] = (str[counter] - 'a') + 'A';
      counter++;
    }
  return (str);
}
