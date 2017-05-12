/*
** struct.h for colle_cocktail in /home/le-mee_b/rendu/colle/my_cocktail/colle_cocktail/include
**
** Made by Boris Le Méec
** Login   <le-mee_b@epitech.net>
**
** Started on  Wed Dec 02 14:10:18 2015 Boris Le Méec
** Last update Wed Dec 02 14:30:57 2015 Boris Le Méec
*/
#include <stdbool.h>

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct s_place
{
  struct s_place	*next;
  struct s_place	*prev;
  char	*drink;
} t_place;

int	add_drink(t_place **, char *);
void	display_list(t_place **);

#endif /* !STRUCT_H_ */
