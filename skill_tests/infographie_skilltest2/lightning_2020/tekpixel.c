/*
** tekpixel.c for tekpixel in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Nov  9 14:24:00 2015 Alexis Viguié
** Last update Mon Nov  9 16:17:04 2015 Alexis Viguié
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 unsigned int		color)
{
  pix->clipable.buffer.width = 1;
  pix->clipable.buffer.height = 1;
  //  pix->pixels[pos->x * (pos->y - 1)] = color;
}
