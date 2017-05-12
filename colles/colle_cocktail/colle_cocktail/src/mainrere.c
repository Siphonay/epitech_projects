/*
** main.c for colle_cocktail in /home/le-mee_b/rendu/colle/my_cocktail/colle_cocktail/src
**
** Made by Boris Le Méec
** Login   <le-mee_b@epitech.net>
**
** Started on  Wed Dec 02 14:08:41 2015 Boris Le Méec
** Last update Wed Dec 02 15:35:12 2015 Boris Le Méec
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "struct.h"
#include "cocktail.h"

int		main()
{
  t_place	*places;
  t_place	*server;
  char		*buffer;

  places = NULL;
  initialize_comptoir(&places);
  server = places;
  if ((buffer = malloc(2048 * sizeof(char))) == NULL)
      return (1);
  while (!(buffer[0] == '0' && buffer[1]  == '\n'))
    {
      if ((buffer = malloc(2048 * sizeof(char))) == NULL)
	  return (1);
      read(0, buffer, 2048);
      if (verif_string(buffer))
	  return (1);
      move_and_serve(&server, my_get_nbr(buffer), get_cocktail(buffer));
    }
  display_list(&places);
  free_list(&places);
  free(buffer);
  return (0);
}
