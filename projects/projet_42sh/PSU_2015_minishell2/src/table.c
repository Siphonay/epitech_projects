/*
** table.c for table in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 18:19:01 2016 thibault derbre
** Last update Sat Apr  9 02:34:59 2016 thibault derbre
*/

#include <stdlib.h>
#include "mysh.h"

void	free_char_table(char **tableau)
{
  free (tableau[0]);
  free (tableau);
}

char    **create_char_table(int nblin, int nbcol)
{
  int   i;
  char	**tableau;
  char 	*tableau2;

  i = 0;
  if ((tableau2 = malloc(sizeof(*tableau2) * nbcol * nblin)) == NULL)
    return (NULL);
  if ((tableau = malloc(sizeof(*tableau) * nblin)) == NULL)
    return (NULL);
  while (i < nblin)
    {
      tableau[i] = &(tableau2[i * nbcol]);
      i++;
    }
  return (tableau);
}

char    **writing_table(char *str, char **table, int word)
{
  int   i;
  int   y;
  int   x;

  y = 0;
  i = 0;
  x = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  table[y][x] = '\0';
	  i++;
	  x = 0;
	  y++;
	}
      table[y][x] = str[i];
      x++;
      i++;
    }
  table[y][x] = '\0';
  table[word + 1] = NULL;
  return (table);
}

char    **str_to_wordtab(char *str)
{
  int   i;
  int   word;
  char  **table;

  i = 0;
  word = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	word++;
      i++;
    }
  table = create_char_table(word + 2, i + 1);
  i = 0;
  table = writing_table(str, table, word);
  return (table);
}

void	show_table(char **table)
{
  int	y;

  y = 0;
  while (table[y] != NULL)
    {
      my_putstr(table[y]);
      my_putchar('\n');
      y++;
    }
}
