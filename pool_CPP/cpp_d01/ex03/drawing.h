/*
** drawing.h for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Wed Jan  4 17:17:55 2017 Alexis Viguié
** Last update Wed Jan  4 17:50:02 2017 Alexis Viguié
*/

#include <stdint.h>
#include <stdlib.h>

typedef struct	s_point
{
  uint32_t	x;
  uint32_t	y;
}		t_point;

void	draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color);
