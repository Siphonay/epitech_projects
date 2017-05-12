/*
** main.c for antoine in /home/antoine
**
** Made by gannat-a
** Login   <antoine@epitech.net>
**
** Started on  Fri Dec 04 18:58:21 2015 gannat-a
** Last update Fri Dec 04 19:00:52 2015 gannat-a
*/

#include <ncurses.h>

int	main()
{
  int	key = 0;

  initscr();
  noecho();
  keypad(stdscr, TRUE);
  key = getch();
  endwin();
  printf("%d\n", key);
  return (0);
}
