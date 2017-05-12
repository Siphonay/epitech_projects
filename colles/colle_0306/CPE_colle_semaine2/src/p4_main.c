/*
** p4_main.c for colle2 in /home/sam/Rendu/Colles/colle_0306/CPE_colle_semaine2/src
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May  3 17:33:45 2016 Alexis Viguié
** Last update Tue May  3 17:33:48 2016 Alexis Viguié
*/

#include "p4.h"
#include <stdlib.h>

int		main(int __attribute__((unused)) ac, char **av)
{
  t_p4_opts	*options;

  if (!(options = malloc(sizeof(t_p4_opts))))
    return (42);
  if (p4_parse_options(av, options))
    return (1);
  return (p4_game_loop(options));
}
