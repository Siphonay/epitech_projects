/*
** table.c for table in /home/zaza/rendu/test/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 09:12:39 2016 thibault derbre
** Last update	Sun Jun 05 13:34:11 2016 pedron_s
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
