/*
** end_game.c for Colle in /home/joly_r/rendu/Colles/Colle2/Colle2/src
**
** Made by joly_r
** Login   <joly_r@epitech.net>
**
** Started on  Tue May  3 17:15:39 2016 joly_r
** Last update Tue May  3 17:33:03 2016 Alexis Viguié
*/

#include "p4.h"
#include "my.h"

void	end_game(char **board, char a)
{
  print_board(board);
  my_putstr("Congrats, player ");
  my_putchar(a);
  my_putstr(" won !\n");
}
