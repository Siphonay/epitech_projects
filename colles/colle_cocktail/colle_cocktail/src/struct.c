/*
** struct.c for colle_cocktail in /home/le-mee_b/rendu/colle/my_cocktail/colle_cocktail/src
**
** Made by Boris Le Méec
** Login   <le-mee_b@epitech.net>
**
** Started on  Wed Dec 02 14:12:05 2015 Boris Le Méec
** Last update Wed Dec 02 15:38:07 2015 Boris Le Méec
*/

#include <stdbool.h>
#include <stdlib.h>
#include "struct.h"
#include "cocktail.h"

void	initialize_comptoir(t_place **list)
{
  int	place;

  place = 0;
  while (place < 12)
    {
      add_drink(list, "vide");
      place++;
    }
}

void	display_list(t_place **list)
{
  t_place	*first;
  bool	stop;

  stop = false;
  (*list) = (*list)->prev;
  first = *list;
  while (!stop)
    {
      (*list) = (*list)->next;
      my_putstr((*list)->drink);
      my_putstr(" ");
      if (*list == first)
	stop = true;
    }
  (*list) = (*list)->prev;
}

int	add_drink(t_place **list, char *drink)
{
  t_place	*elem;

  if ((elem = malloc(sizeof(t_place))) == NULL)
    return (0);
  elem->drink = drink;
  if (*list != NULL)
    {
      elem->next = *list;
      elem->prev = (*list)->prev;
      elem->prev->next = elem;
      (*list)->prev = elem;
    }
  else
    {
      elem->next = elem;
      elem->prev = elem;
    }
  *list = elem;
  return (1);
}

void	move_and_serve(t_place **server, int where, char *what)
{
  int	position_start;
  int	incr;

  incr = 1;
  if (where < 0)
    incr = -1;
  position_start = 0;
  while (position_start != where)
    {
      if (incr == -1)
	*server = (*server)->prev;
      else
	*server = (*server)->next;
      position_start += incr;
    }
  (*server)->drink = what;
}

// void	empty_list(t_place **list)
// {
//   t_place	*tmp;
//
//   tmp = *list;
//   if (*list != NULL)
//     {
//       while ((*list)->next != tmp)
// 	{
// 	  *list = (*list)->next;
// 	  free ((*list)->prev);
// 	}
//       free (*l_a);
//   }
// }
