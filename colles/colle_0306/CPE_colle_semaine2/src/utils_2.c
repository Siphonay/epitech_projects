/*
** utils_2.c for colle2 in /home/sam/Rendu/Colles/colle_0306/CPE_colle_semaine2/src
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May  3 17:34:38 2016 Alexis Viguié
** Last update Tue May  3 17:37:45 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

void	print_board(char **board)
{
  int	i;

  i = 0;
  while (board[i] != NULL)
    {
      my_putstr(board[i]);
      my_putstr("\n");
      i++;
    }
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
}

void	fill_line(char **board, int width, int i)
{
  int	k;

  k = 1;
  board[i][0] = '|';
  while (k <= width)
    {
      board[i][k] = ' ';
      k++;
    }
  board[i][k] = '|';
  board[i][k + 1] = '\0';
}

bool	my_strcmp(const char *s1, const char *s2)
{
  int   i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (false);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
        return (false);
      i++;
    }
  return (true);
}
