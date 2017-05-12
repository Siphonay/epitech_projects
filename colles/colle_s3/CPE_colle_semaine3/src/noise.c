/*
** noise.c for 512 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3
** 
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
** 
** Started on  Tue May 10 19:46:21 2016 Stanislav HEURTAULT
** Last update Tue May 10 19:49:00 2016 Stanislav HEURTAULT
*/

#include <lapin.h>
#include "game_512.h"

int	noise_color_full(t_bunny_pixelarray *pix, t_color *color)
{
  t_bunny_position pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y <= pix->clipable.clip_height)
    {
      while (pos.x <= pix->clipable.clip_width)
	{
	  tekpixel(pix, &pos, color);
	  pos.x++;
	}
      pos.x = 0;
      pos.y++;
    }
  return (0);
}
