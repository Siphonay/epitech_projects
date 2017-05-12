/*
** bsq_disp.c for bsq in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 16:00:42 2015 Alexis Viguié
** Last update Sun Dec 20 14:20:30 2015 Alexis Viguié
*/

#include <unistd.h>
#include "bsq.h"

int	get_rowlen(char *plat)
{
  int	counter;

  counter = 0;
  while (plat[counter] != '\n')
    counter++;
  return (counter + 1);
}

int	check_square(t_coord pos, char *plat, int row_qt, int rowlen)
{
  int	size;
  int	obst;
  int	counter;
  int	counter2;

  size = 0;
  obst = 0;
  while (!obst && size + pos.y < row_qt && size + pos.x < rowlen)
    {
      counter = 0;
      while (counter <= size && !obst)
	{
	  counter2 = 0;
	  while (counter2 <= size && !obst)
	    {
	      if (plat[((counter + pos.y) * rowlen) + counter2 + pos.x] != '.')
		obst = 1;
	      counter2++;
	    }
	  counter++;
	}
      if (!obst)
	size++;
    }
  return (size);
}

void	disp_plat(char *plat, t_square square, int rowlen)
{
  int	counter;

  counter = 0;
  while (plat[counter])
    {
      if ((counter / rowlen >= square.init_pos.y) &&
	  (counter / rowlen < square.init_pos.y + square.size))
	{
	  if ((counter % rowlen >= square.init_pos.x) &&
	      (counter % rowlen  < square.init_pos.x + square.size))
	    write(1, "x", 1);
	  else
	    write(1, &plat[counter], 1);
	}
      else
	write(1, &plat[counter], 1);
      counter++;
    }
}

void		proc_plat(char *plat, int row_number)
{
  t_coord	coord;
  t_square	square;
  int     	cur_size;
  int		rowlen;

  rowlen = get_rowlen(plat);
  coord.x = row_number;
  coord.y = 0;
  square.init_pos = coord;
  square.size = 0;
  while (coord.y < row_number)
    {
      coord.x = 0;
      while (coord.x < get_rowlen(plat))
	{
	  if ((cur_size = check_square(coord, plat, row_number, rowlen)) > square.size)
	    {
	      square.init_pos = coord;
	      square.size = cur_size;
	    }
	  coord.x++;
	}
      coord.y++;
    }
  disp_plat(plat, square, rowlen);
}
