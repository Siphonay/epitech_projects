/*
** my_str_to_wordtab.c for str_to_wordtab in /home/herlin_a/rendu/PSU/PSU_2015_minishell1
**
** Made by Victor Herlin
** Login   <herlin_a@epitech.net>
**
** Started on  Fri Jan 22 09:07:14 2016 Victor Herlin
** Last update Mon Mar 28 15:06:52 2016 Victor Herlin
*/

#include "asm.h"

char    **while_to_word_tab(char *str, char **wordtab, char sep, int y)
{
  int   i;
  int   x;

  i = 0;
  x = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
        {
          wordtab[y][x] = '\0';
          y++;
          if ((wordtab[y] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
            return (NULL);
          x = 0;
        }
      else
        {
          wordtab[y][x] = str[i];
          x++;
        }
      i++;
    }
  wordtab[y + 1] = NULL;
  return (wordtab);
}

char    **my_str_to_wordtab(char *str, char sep)
{
  char  **wordtab;
  int   y;

  y = 0;
  if ((wordtab = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  if ((wordtab[y] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  if (while_to_word_tab(str, wordtab, sep, y) == NULL)
    return (NULL);
  return (wordtab);
}

void    my_show_wordtab(char **wordtab)
{
  int   i;

  i = 0;
  while (wordtab[i] != NULL)
    {
      my_putstr(wordtab[i]);
      my_putchar('\n');
      i++;
    }
}
