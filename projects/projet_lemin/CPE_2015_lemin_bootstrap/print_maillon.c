/*
** print_maillon.c for bootstrap lemin in /home/sam/Rendu/Projets/projet_lemin/CPE_2015_lemin_bootstrap
**
** Made by
** Login   <sam@epitech.net>
**
** Started on  Wed Apr  6 14:09:16 2016
** Last update Wed Apr  6 14:10:20 2016 
*/

#include <unistd.h>
#include "graph.h"

void	print_maillon(t_maillon *maillon)
{
  lb_putnbr(maillon->data);
  write(1, "\n", 1);
}
