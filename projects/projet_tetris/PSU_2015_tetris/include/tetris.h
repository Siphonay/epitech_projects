/*
** tetris.h for tetris in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Mar 10 17:33:03 2016 Alexis Viguié
** Last update Fri Mar 11 15:53:04 2016 Alexis Viguié
*/

#ifndef TETRIS_H_
# define TETRIS_H_

#include <stdbool.h>

typedef struct	s_game_params
{
  unsigned int	baselevel;
  unsigned int	map_size[2];
  bool		disp_next;
  bool		debug_mode;
}		t_game_params;

typedef struct	s_game_keys
{
  char		left;
  char		right;
  char		turn;
  char		drop;
  char		quit;
  char		pause;
}		t_game_keys;

#endif /* !TETRIS_H_ */
