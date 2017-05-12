/*
** my_str_to_wordtab.c for my str to wordtab in /home/viguie_a/rendu_j08/Piscine_C_J08/ex_04
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Wed Oct  7 16:50:23 2015 Alexis Viguié
** Last update Wed Oct  7 21:22:29 2015 Alexis Viguié
*/

#include <stdlib.h>

int	char_isalpha(char chr)
{
  if ((chr > 96 && chr < 123) || (chr > 65 && chr < 91))
    return (1);
  else
    return (0);
}

int     char_isnum(char chr)
{
  if (chr > 47 && chr < 58)
    return (1);
  else
    return (0);
}

int	wordtab_len(char *str)
{
  int	counter;
  int	split;

  counter = 0;
  split = 0;
  while (str[counter] != '\0')
    {
      if (counter > 0 && char_isalpha(str[counter]) && char_isnum(str[counter]))
	split++;
      counter++;
    }
  if (!(char_isalpha(str[counter - 1])) && !(char_isnum(str[counter - 1])))
    split--;
}

char	**my_str_to_wordtab(char *str)
{
  int	counter;
  int	counter2;
  char	**dest;

  counter = 0;
  *dest = malloc(wordtab_len(str));
  while (counter < wordtab_len(str))
    {
      while (char_isalpha(str[counter2]) && char_isnum(str[counter2]))
	{
	  dest[counter][counter2] = str[counter2];
	  counter2++;
	}
      while (!(char_isalpha(str[counter2])) && !(char_isnum(str[counter2])))
        {
          counter2++;
        }
      counter++;
    }
  return (dest);
}
