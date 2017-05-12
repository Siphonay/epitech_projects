/*
** my_set_pixel.c for my set pixel in /home/sam/noise/tp
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Nov  2 15:41:19 2015 Alexis Viguié
** Last update Mon Nov  2 22:06:49 2015 Alexis Viguié
*/

#include <lapin.h>

t_bunny_my_set_pixel	bunny_my_set_pixel(t_bunny_pixelarray	*pix,
					   t_bunny_position	pos,
					   unsigned int		color)
{
  &pix->pixels[pos.y * pos.x + pos.x] = ;
}
