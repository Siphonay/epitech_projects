/*
** color_palette.c for rush incendie in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Dec  6 11:52:40 2015 Alexis Viguié
** Last update Sun Dec  6 16:52:04 2015 Alexis Viguié
*/

#include <stdlib.h>

int	*gen_palette()
{
  int	*cpal;
  int	counter;
  int	color;

  counter = 0;
  if ((cpal = malloc(128 * sizeof(int))) == NULL)
    exit(1);
  while (counter < 128)
    {
      if (counter < 32)
	color += (65536 * 8);
      else if (counter < 64)
	color += (256 * 8);
      else if (counter < 96)
	color += 8;
      else
	color = 0xFFFFFF;
      cpal[counter] = color;
      counter++;
    }
return (cpal);
}
