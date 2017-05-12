/*
** str_lines_to_wordtab.c for SBMLparser in /home/sam/Rendu/Piscine_S/projet_1/SBMLparser
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Jun 14 09:12:58 2016 Alexis Viguié
** Last update Tue Jun 14 09:45:28 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>

int	count_lines(char *str)
{
  int	counter;
  int	lines_ret;

  counter = lines_ret = 0;
  while (str[counter])
    {
      while (str[counter] && str[counter] == '\n')
	counter++;
      if (str[counter])
	{
	  lines_ret++;
	  while (str[counter] && str[counter] != '\n')
	    counter++;
	}
    }
  return (lines_ret);
}

char	*get_strline(char *str)
{
  int	counter;
  char	*line_ret;

  counter = 0;
  while (str[counter] && str[counter] != '\n')
    counter++;
  if (str[0] == '\n' ||
      !(line_ret = malloc(sizeof(char) * (counter + 1))) ||
      !(line_ret = strncpy(line_ret, str, counter)))
    return (NULL);
  line_ret[counter] = '\0';
  return (line_ret);
}

char	**str_lines_to_wordtab(char *str)
{
  int	counter;
  int	counter2;
  char	**wordtab_ret;

  counter = counter2 = 0;
  if (!(wordtab_ret = malloc(sizeof(char*) * (count_lines(str) + 1))))
    return (NULL);
  wordtab_ret[count_lines(str)] = NULL;
  while (str[counter])
    {
      while (str[counter] && str[counter] == '\n')
	counter++;
      if (str[counter])
	{
	  if (!(wordtab_ret[counter2] = get_strline(&str[counter])))
	    return (NULL);
	  counter2++;
	  while (str[counter] && str[counter] != '\n')
	    counter++;
	}
    }
  return (wordtab_ret);
}
