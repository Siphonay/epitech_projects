/*
** create_maillon.c for bootstrap lemin in /home/sam/Rendu/Projets/projet_lemin/CPE_2015_lemin_bootstrap
**
** Made by
** Login   <sam@epitech.net>
**
** Started on  Wed Apr  6 14:01:38 2016
** Last update Thu Apr  7 13:31:21 2016 
*/

#include <stdlib.h>
#include "graph.h"

t_maillon	*create_maillon(int data)
{
  t_maillon	*ret_maillon;

  if ((ret_maillon = malloc(sizeof(t_maillon))) == NULL)
    return (NULL);
  ret_maillon->data = data;
  ret_maillon->next = NULL;
  return (ret_maillon);
}
