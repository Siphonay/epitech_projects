/*
** tekpixel.c for chatty in /home/sam/Rendu/Skill Tests/chatty_2020
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 18 16:44:50 2016 Alexis Viguié
** Last update Thu Feb 18 16:44:51 2016 Alexis Viguié
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
