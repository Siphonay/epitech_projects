/*
** tekpixel.c<mystic_2020> for mystic in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 11 09:22:03 2016 Alexis Viguié
** Last update Thu Feb 25 19:41:16 2016 Alexis Viguié
*/

#include <lapin.h>
#include <math.h>
#include "mystic.h"

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 unsigned int color)
{
  unsigned int	*toset_pix;

  toset_pix = pix->pixels;
  toset_pix[pix->clipable.buffer.width * pos->y + pos->x] = color;
}

void			tekcircle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  double radius,
				  unsigned int	color)
{
  t_bunny_position	cur_pos;
  unsigned int		counter;
  float			cur_point;
  float			curcos;
  float			cursin;

  counter = (cur_point = 0);
  while (counter != 36000)
    {
      curcos = cos((cur_point * M_PI) / 180.0f);
      cursin = sin((cur_point * M_PI) / 180.0f);
      cur_pos.x = pos->x + radius * curcos;
      cur_pos.y = pos->y + radius * cursin;
      tekpixel(pix, &cur_pos, color);
      cur_point += 0.01f;
      counter++;
    }
}

void			mystic_clock(t_bunny_pixelarray *pix,
				     const t_bunny_circle *circle,
				     double angle,
				     size_t depth)
{
  unsigned int		counter;
  unsigned int		cur_color;
  double		cur_radius;
  t_bunny_position	cur_pos;

  counter = 0;
  cur_color = circle->color;
  cur_pos = circle->position;
  cur_radius = circle->radius;
  while (counter < depth)
    {
      tekcircle(pix, &cur_pos, cur_radius, cur_color);
      cur_pos.x += cos(angle) * cur_radius;
      cur_pos.y += sin(angle) * cur_radius;
      angle+= -angle * 2;
      cur_radius /= 2;
      cur_color = WHITE - cur_color;
      counter++;
    }
}
