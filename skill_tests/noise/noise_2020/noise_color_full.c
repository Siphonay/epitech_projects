/*
** noise_color_full.c for noise in /home/sam/noise/noise_2020
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Nov  2 14:17:54 2015 Alexis Viguié
** Last update Mon Nov  2 16:03:58 2015 Alexis Vigui�
*/

#include <stdlib.h>
#include <lapin.h>

void	noise_color_full(t_bunny_pixelarray *pix)
{
  char	color[4];
  int	counter;
  int	counter2;
  int	counter3;

  counter = 0;
  counter2 = 0;
  color[3] = 255;
  while (counter < pix.clipable.buffer.height)
    {
      if (counter2 > pix.clipable.buffer.length)
	{
	  counter2 = 0;
	  counter++;
	}
      counter3 = 0;
      while (counter3 < 2)
	{
	  color[counter3] = rand(0, 255);
	  counter3++;
	}
      pix.pixels[counter * pix.clipable.buffer.height + counter2] = color;
      counter2++;
    }
}
