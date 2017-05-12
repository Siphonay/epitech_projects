/*
** load_grid.c for 51 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
** 
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
** 
** Started on  Tue May 10 19:56:50 2016 Stanislav HEURTAULT
** Last update Tue May 10 20:37:31 2016 Stanislav HEURTAULT
*/

#include <lapin.h>
#include <stdio.h>
#include "game_512.h"

unsigned int	get_color(t_bunny_pixelarray *pix, t_bunny_position pos,
			  t_bunny_position keep, t_data *data)
{
  unsigned int	color;

  keep.x += (64 * data->grid[pos.y][pos.x]);
  color = getpixel(pix, &keep);
  return (color);
}

int	take_in_pix(t_data *data, t_bunny_position pos)
{
  t_bunny_position	keep;
  t_bunny_position	actu;
  t_color		color;

  keep.x = 0;
  keep.y = 0;
  actu.x = pos.x * 64;
  actu.y = pos.y * 64;
  while (keep.y < 64)
    {
      while (keep.x < 64)
	{
	  color.full = get_color(data->font, pos, keep, data);
	  tekpixel(data->pix, &actu, &color);
	  actu.x++;
	  keep.x++;
	}
      keep.x = 0;
      keep.y++;
      actu.x = pos.x * 64;
      actu.y++;
    }
  return (0);
}

int	load_grid(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < GRID_SIZE)
    {
      while (pos.x < GRID_SIZE)
	{
	  take_in_pix(data, pos);
	  pos.x++;
	}
      pos.x = 0;
      pos.y++;
    }
  return (0);
}
