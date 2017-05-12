/*
** checkers_setcheckers.c for Red Alers in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Tue Mar 15 09:41:16 2016 Alexis Viguié
** Last update Tue Mar 15 10:24:09 2016 Alexis Viguié
*/

#include <lapin.h>
#include "checkers.h"

void	checkers_setpixel(t_bunny_data *data,
			  t_bunny_position toset_pos,
			  unsigned int color)
{
  unsigned int	*toset_pix;

  toset_pix = data->pix->pixels;
  toset_pix[data->pix->clipable.buffer.width * toset_pos.y + toset_pos.x] =
    color;
}

unsigned int		checkers_setcheckers(t_bunny_data *check_data)
{
  t_bunny_position	checkers_pos;
  unsigned int		cur_color;

  checkers_pos.x = 0;
  cur_color = WHITE;
  if (!(check_data->size.x / CHECKERS_SIZE) ||
      !(check_data->size.y / CHECKERS_SIZE))
    return (1);
  while (checkers_pos.y < check_data->size.y)
    {
      if (checkers_pos.y && !(checkers_pos.y %
			      (check_data->size.y / CHECKERS_SIZE)))
	cur_color = WHITE - cur_color;
      checkers_pos.x = 0;
      while (checkers_pos.x < check_data->size.x)
	{
	  if (checkers_pos.x && !(checkers_pos.x %
				  (check_data->size.x / CHECKERS_SIZE)))
	    cur_color = WHITE - cur_color;
	  checkers_setpixel(check_data, checkers_pos, cur_color);
	  checkers_pos.x++;
	}
      checkers_pos.y++;
    }
  return (0);
}
