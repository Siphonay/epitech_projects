/*
** print_data_des_maillons_connexes.c for boostrap lemin in /home/sam/Rendu/Projets/projet_lemin/CPE_2015_lemin_bootstrap
**
** Made by
** Login   <sam@epitech.net>
**
** Started on  Wed Apr  6 14:20:31 2016
** Last update Wed Apr  6 14:22:31 2016 
*/

#include "graph.h"

void	print_data_des_maillons_connexes(t_maillon *maillon)
{
  while (maillon->next)
    {
      maillon = maillon->next;
      print_maillon(maillon);
    }
}
