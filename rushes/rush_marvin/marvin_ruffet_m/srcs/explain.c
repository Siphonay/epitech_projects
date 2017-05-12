/*
** explain.c for explain_str in /home/ruffetm/rendu/RUSH/marvin_ruffet_m/srcs
**
** Made by Mathieu RUFFET
** Login   <ruffetm@epitech.net>
**
** Started on  Sat May 14 10:40:00 2016 Mathieu RUFFET
** Last update Sat May 14 16:50:14 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "marvin.h"

int	fun_or_var(char *str)
{
  int	i_str;
  int	nb_par;

  nb_par = 0;
  i_str = 0;
  while (str[i_str])
    {
      if (str[i_str] == 40)
	nb_par++;
      if (str[i_str] == 41)
	nb_par++;
      i_str++;
    }
  if (str[strlen(str) - 1] != ';' || nb_par % 2 != 0)
    return (-1);
  else
    return (nb_par);
}

bool	is_var(char *str)
{
  if ((fun_or_var(str)) == -1)
    {
      printf("erreur syntaxe, expression non reconnue.\n");
      exit(EXIT_FAILURE);
    }
  else
    return (!fun_or_var(str));
}
