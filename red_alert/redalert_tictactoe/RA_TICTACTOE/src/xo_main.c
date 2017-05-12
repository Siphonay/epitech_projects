/*
** xo_main.c for tic tac toe in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Feb  8 10:44:21 2016 Alexis Viguié
** Last update Wed Feb 10 10:06:10 2016 Alexis Viguié
*/

#include <ncurses.h>
#include <stdbool.h>
#include "xo.h"

int		main()
{
  WINDOW	*xo_win;
  t_winsize	xo_winsize;

  xo_win = initscr();
  noecho();
  getmaxyx(xo_win, xo_winsize.y, xo_winsize.x);
  if (xo_winsize.x < XO_MIN_SIZE || xo_winsize.y < XO_MIN_SIZE)
    exit_wintoosmall();
  mvprintw(0, 0, XO_GRID);
  while (xo_play());
  clear();
  endwin();
  return (0);
}
