/*
** requirement.c for SBMLparser in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 13 09:12:16 2016 Alexis Viguié
** Last update Tue Jun 14 09:29:28 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <stdbool.h>

bool	my_isalpha(char c)
{
  return ((c >= 'A' && c <= 'Z') ||
	  (c >= 'a' && c <= 'z') ||
	  (c >= '0' && c <= '9'));
}

int	count_words(char *str)
{
  int	counter;
  int	words_ret;

  counter = words_ret = 0;
  while (str[counter])
    {
      while (str[counter] && !my_isalpha(str[counter]))
	counter++;
      if (str[counter])
	{
	  words_ret++;
	  while (str[counter] && my_isalpha(str[counter]))
	    counter++;
	}
    }
  return (words_ret);
}

char	*getword(char *str)
{
  int	counter;
  char	*word_ret;

  counter = 0;
  while (str[counter] && my_isalpha(str[counter]))
    counter++;
  if (!my_isalpha(str[0]) ||
      !(word_ret = malloc(sizeof(char) * (counter + 1))))
    return (NULL);
  word_ret[counter] = '\0';
  counter = 0;
  while (str[counter] && my_isalpha(str[counter]))
    {
      word_ret[counter] = str[counter];
      counter++;
    }
  return (word_ret);
}

char	**my_strtowordtab_synthesis(char *str)
{
  int	counter;
  int	counter2;
  char	**wordtab_ret;

  counter = counter2 = 0;
  if (!(wordtab_ret = malloc(sizeof(char*) * (count_words(str) + 1))))
    return (NULL);
  wordtab_ret[count_words(str)] = NULL;
  while (str[counter])
    {
      while (str[counter] && !my_isalpha(str[counter]))
	counter++;
      if (str[counter])
	{
	  if (!(wordtab_ret[counter2] = getword(&str[counter])))
	      return (NULL);
	  counter2++;
	  while (str[counter] && my_isalpha(str[counter]))
	    counter++;
	}
    }
  return (wordtab_ret);
}
