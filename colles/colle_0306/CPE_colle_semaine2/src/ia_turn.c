/*
** ia_turn.c for Colle in /home/joly_r/rendu/Colles/Colle2/Colle2/src
** 
** Made by joly_r
** Login   <joly_r@epitech.net>
** 
** Started on  Tue May  3 15:49:34 2016 joly_r
** Last update Tue May  3 16:52:34 2016 joly_r
*/

#include <stdlib.h>
#include "p4.h"

void	ia_turn(char **board, char avatar, t_p4_opts option)
{
  int	col;

  col = (rand() % option.width) + 1;
  fill_board(board, col, option, avatar);
}
