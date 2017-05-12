/*
** xo_play.c for tic tac toe in /home/sam/Rendu/Red Alert/redaltert_tictactoe/RA_TICTACTOE/include
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Feb 10 09:23:06 2016 Alexis Viguié
** Last update Wed Feb 10 10:02:20 2016 Alexis Viguié
*/

#include <ncurses.h>
#include "xo.h"

void			disp_grid(unsigned short *xo_grid)
{
  unsigned short	x_counter;
  unsigned short	y_counter;
  unsigned short	counter;

  counter = (y_counter = 0);
  while (y_counter < 6)
    {
      x_counter = 0;
      while (x_counter < 6)
	{
	  mvprintw(y_counter, x_counter, &XO_SYMBOLS[xo_grid[counter]]);
	  x_counter += 2;
	  counter++;
	}
      y_counter += 2;
    }
}
