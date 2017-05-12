/*
** cocktail.h for colle cocktail in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Dec  2 14:14:16 2015 Alexis Viguié
** Last update Wed Dec 02 15:46:49 2015 Boris Le Méec
*/

#include "struct.h"

#ifndef COCKTAIL_H_
# define COCKTAIL_H_
int	my_get_nbr(char *str);
void	my_putstr(char *str);
void	my_putstr_err(char *str);
void	initialize_comptoir(t_place **list);
void	move_and_serve(t_place **, int, char *);
int	my_isnum(char c);
int	verif_string(char *drink_input);
char	*get_cocktail(char *drink_input);
#endif /* !COCKTAIL_H_ */
