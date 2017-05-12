/*
** drawing.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Wed Jan  4 17:24:19 2017 Alexis Viguié
** Last update Wed Jan  4 18:07:40 2017 Alexis Viguié
*/

#include <stdint.h>
#include "drawing.h"

void		draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color)
{
  uint32_t	counter_x;
  uint32_t	counter_y;

  counter_y = orig->y;
  while (counter_y < orig->y + size)
    {
      counter_x = orig->x;
      while (counter_x < orig->x + size)
	{
	  img[counter_y][counter_x] = color;
	  counter_x++;
	}
      counter_y++;
    }
}
