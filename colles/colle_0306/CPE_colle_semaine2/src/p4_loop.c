/*
** main.c for Colle in /home/joly_r/rendu/Colles/Colle2/Colle2/src
**
** Made by joly_r
** Login   <joly_r@epitech.net>
**
** Started on  Tue May  3 14:34:07 2016 joly_r
** Last update Tue May  3 17:36:45 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "p4.h"
#include "my.h"

void	draw_end_map(char **board, t_p4_opts *option, int i)
{
  int	k;

  k = 1;
  board[i][0] = '+';
  while (k <= option->width)
    {
      board[i][k] = '-';
      k++;
    }
  board[i][k] = '+';
  board[i][k + 1] = '\0';
}

char	**malloc_board(t_p4_opts *option)
{
  char	**board;
  int	i;

  i = 0;
  if ((board = malloc(sizeof(char*) * (option->height + 2))) == NULL)
    return (NULL);
  while (i < option->height)
    {
      if ((board[i] = malloc(sizeof(char) * (option->width + 3))) == NULL)
	return (NULL);
      fill_line(board, option->width, i);
      i++;
    }
  if ((board[i] = malloc(sizeof(char) * (option->width + 3))) == NULL)
    return (NULL);
  draw_end_map(board, option, i);
  board[i + 1] = NULL;
  return (board);
}


char	play_turn(t_p4_opts *option, char **board, int ind)
{
  if (ind == 1)
    {
      player_turn(board, option->p1_avatar, *option);
      if ((check_board(board, option->p1_avatar, option)) == option->p1_avatar)
	return (option->p1_avatar);
    }
  else if (ind == 2)
    {
      ia_turn(board, option->a_avatar, *option);
      if ((check_board(board, option->a_avatar, option)) == option->a_avatar)
        return (option->a_avatar);
    }
  else if (ind == 3)
    {
      player_turn(board, option->p2_avatar, *option);
      if ((check_board(board, option->p2_avatar, option)) == option->p2_avatar)
	return (option->p2_avatar);
    }
  return ('N');
}

int	p4_game_loop(t_p4_opts *option)
{
  char	**board;
  char	a;

  if ((board = malloc_board(option)) == NULL)
    return (-1);
  while (1)
    {
      if ((a = play_turn(option, board, 1)) == option->p1_avatar)
	break;
      if (option->ia)
	{
	  if ((a = play_turn(option, board, 2)) == option->a_avatar)
	    break;
	}
      else
	{
	  if ((a = play_turn(option, board, 3)) == option->p2_avatar)
	    break;
	}
    }
  end_game(board, a);
  free_tab(board);
  free(option);
  return (0);
}
