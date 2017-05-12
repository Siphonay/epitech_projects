/*
** get_quoted_str.c for SBMLparser in /home/sam/Rendu/Piscine_S/projet_1/SBMLparser
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jun 15 10:21:40 2016 Alexis Viguié
** Last update Wed Jun 15 16:52:26 2016 Alexis Viguié
*/

#include <stdlib.h>

char	*get_quoted_str(char *str, char quote)
{
  int	counter;
  char	*ret_str;

  counter = 0;
  while (str[counter] && str[counter] != quote)
    counter++;
  if (!str[counter] || !(ret_str = malloc(sizeof(char) * (counter + 1))))
    return (NULL);
  ret_str[counter] = '\0';
  counter = 0;
  while (str[counter] != quote)
    {
      ret_str[counter] = str[counter];
      counter++;
    }
  return (ret_str);
}
