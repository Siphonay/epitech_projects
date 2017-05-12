/*
** tekpixel.c for flip part in /home/sam/Rendu/Skill/flip_part_2020
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Tue Feb 23 14:15:37 2016 Alexis Viguié
** Last update Tue Feb 23 14:40:36 2016 Alexis Viguié
*/

#include "lapin.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*toset_pix;

  if ((pos->x >= 0) && (pos->x <= pix->clipable.buffer.width) &&
      (pos->y >= 0) && (pos->y <= pix->clipable.buffer.height))
    {
      toset_pix = pix->pixels;
      toset_pix[pix->clipable.buffer.width * pos->y + pos->x] = color;
    }
}
