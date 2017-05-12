/*
** tekpixel.c for flashlight in /home/sam/Rendu/Skill Tests
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 18 16:45:20 2016 Alexis Viguié
** Last update Thu Feb 18 16:45:20 2016 Alexis Viguié
*/

#include <lapin.h>
#include <math.h>

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*toset_pix;

  toset_pix = pix->pixels;
  toset_pix[pix->clipable.buffer.width * pos->y + pos->x] = color;
}
