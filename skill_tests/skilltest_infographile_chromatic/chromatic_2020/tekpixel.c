/*
** tekpixel.c for skill test chromatic in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Feb  3 15:35:44 2016 Alexis Viguié
** Last update Thu Feb 11 09:26:13 2016 Alexis Viguié
*/

#include <lapin.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*toset_pix;

  toset_pix = pix->pixels;
  toset_pix[pix->clipable.buffer.width * pos->y + pos->x] = color;
}
