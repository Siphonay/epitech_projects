/*
** tekpixel.c for  in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
** 
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
** 
** Started on  Tue May 10 19:20:07 2016 Stanislav HEURTAULT
** Last update Tue May 10 20:26:33 2016 Stanislav HEURTAULT
*/

#include <lapin.h>
#include "game_512.h"

int	tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color)
{
  unsigned int	position;

  position = pos->x + (pos->y * pix->clipable.clip_width);
  ((unsigned int *)pix->pixels)[position] = color->full;
  return (0);
}
