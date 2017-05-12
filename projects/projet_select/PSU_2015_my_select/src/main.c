/*
** main.c for my select in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec  4 14:58:09 2015 Alexis Viguié
** Last update Mon Dec 14 15:34:48 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <ncurses.h>
#include "sam.h"
#include "select.h"

int	*build_index_table(int ac)
{
  int	*index_ret;
  int	counter;

  if ((index_ret = malloc(sizeof(int) * ac - 1)) == NULL)
    mllc_err();
  counter = 0;
  while (counter < (ac - 1))
    {
      index_ret[counter] = 0;
      counter++;
    }
  return (index_ret);
}

int	disp_select(int *index, char **elems, WINDOW *ncwin, int *wsize)
{
  int	counter;
  int	*ncpos;

  ncpos = build_ncpos_base();
  counter = 1;
  while (elems[counter])
    {
      ncpos = update_ncpos(ncpos, wsize);
      if (index[counter] == 2)
	  wsize[2] = pos_update(elems, wsize[2], counter);
      else
	{
	  if ((sam_strlen(elems[counter]) + ncpos[1]) > wsize[1])
	    wsize_err();
	  setattr(wsize[2], index[counter], counter);
	  ncpos = ncprint_curpos(ncwin, ncpos, elems[counter]);
	}
      counter++;
    }
  return (wsize[2]);
}

int	verif_alldel(int *index, int ac)
{
  int	counter;

  counter = 0;
  while (index[counter] == 2)
    counter++;
  if (counter == (ac - 1))
    return (1);
  else
    return (0);
}

int		main(int ac, char **av)
{
  WINDOW	*ncwin;
  int		wsize[3];
  int		*index;
  int		exit_v;
  int		last_key;

  if (ac < 2)
    arg_err(av);
  index = build_index_table(ac);
  ncwin = initscr();
  noecho();
  keypad(ncwin, true);
  getmaxyx(ncwin, wsize[0], wsize[1]);
  exit_v = 0;
  wsize[2] = 1;
  while (!exit_v && !verif_alldel(index, ac))
    {
      clear();
      wsize[2] = disp_select(index, av, ncwin, wsize);
      refresh();
      last_key = getch();
      if (last_key == 27)
	{
	  exit_v = 1;
	  clear();
	  endwin();
	}
      else if (last_key == ' ')
	{
	  if (index[wsize[2]])
	    index[wsize[2]] = 0;
	  else
	    index[wsize[2]] = 1;
	  wsize[2]++;
	}
      else if ((last_key == KEY_BACKSPACE) || (last_key == KEY_DC))
	{
	  index[wsize[2]] = 2;
	  while (index[wsize[2]] == 2)
	    wsize[2]++;
	}
      else if (last_key == KEY_UP)
	{
	  wsize[2]--;
	  while (index[wsize[2]] == 2)
	    {
	      wsize[2]--;
	      if (wsize[2] == 0)
		wsize[2] = ac - 1;
	    }
	}
      else if (last_key == KEY_DOWN)
	{
	  wsize[2]++;
	  while (index[wsize[2]] == 2)
	    {
	      wsize[2]++;
	      if (wsize[2] == ac)
		wsize[2] = ac;
	    }
	}
      else if (last_key == '\n')
	{
	  print_select_exit(av, index, ac);
	  exit_v = 1;
	}
      if (wsize[2] == 0)
	{
	  wsize[2] = ac - 1;
	  while (index[wsize[2]] == 2)
	    wsize[2]--;
	}
      if (wsize[2] == ac)
	{
	  wsize[2] = 1;
	  while (index[wsize[2]] == 2)
	    wsize[2]++;
	}
    }
  return (0);
}
