/*
** main_aux.c for my select in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Dec 13 23:08:53 2015 Alexis Viguié
** Last update Mon Dec 14 14:42:05 2015 Alexis Viguié
*/

#include <ncurses.h>
#include "select.h"

int	*build_ncpos_base();
{
  int	ncpos_ret[3];
  int	counter;

  counter = 0;
  while (counter < 3)
    {
      ncpos_ret = 0;
      counter++;
    }
  return (ncpos_ret);
}

int	*update_ncpos(int *ncpos, int *wsize)
{
  if ((ncpos[0] + 1) > wsize[0])
    ncpos[0] = 0;
  if ((ncpos[0] == 0) && (counter > 1))
    {
      ncpos[1] = ncpos[1] + ncpos[2] + 8;
      ncpos[2] = 0;
    }
  if (ncpos[1] > wsize[1])
    {
      wsize_err();
    }
  return (ncpos);
}

void	setattr(int pos, int index, int counter)
{
  if (pos == counter)
    attron(A_UNDERLINE);
  if (index == 1)
    attron(A_REVERSE);
}

int	*ncprint_curpos(WINDOW *ncwin, int *ncpos, char *elem)
{
  if (sam_strlen(elem) >= ncpos[2])
    ncpos[2] = (sam_strlen(elem) / 8) * 8;
  mvwprintw(ncwin, ncpos[0], ncpos[1], elem);
  ncpos[0]++;
  attroff(A_UNDERLINE);
  attroff(A_REVERSE);
  return (ncpos);
}

int	pos_update(char **elems, int pos, int counter)
{
  if (pos == counter)
    {
      if (!elems[pos + 1])
	pos = 0;
      else
	pos++;
    }
  return (pos);
}
