/*
** my_popup.c for my popup in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Nov 30 14:06:05 2015 Alexis Viguié
** Last update Fri Dec  4 16:40:47 2015 Alexis Viguié
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my_popup.h"

int		main(int ac, char **av)
{
  WINDOW	*ncwin;
  int		x_size;
  int		y_size;

  if (ac != 2)
    {
      my_putstr_err("please use one and only one string as argument\n");
      return (1);
    }
  ncwin = initscr();
  noecho();
  getmaxyx(ncwin, y_size, x_size);
  mvwprintw(ncwin, (y_size / 2), ((x_size - my_strlen(av[1])) / 2), av[1]);
  while (getch() != ' ');
  clear();
  endwin();
  return (0);
}
