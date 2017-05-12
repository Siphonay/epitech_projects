/*
** c64_chromatic.c for skilltest in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Feb  3 17:11:09 2016 Alexis Viguié
** Last update Wed Feb  3 17:44:23 2016 Alexis Viguié
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 unsigned int color);

void			c64_chromatic(t_bunny_pixelarray *pix,
				      unsigned int	*height,
				      unsigned int	*color,
				      size_t		len)
{
  unsigned int		counter;
  t_bunny_position	curpos;
  int			cur_height;
  int			*int_hei;

  int_hei = (int*)height;
  counter = 0;
  cur_height = 0;
  while (counter < len)
    {
      curpos.y = 0;
      while (curpos.y < int_hei[counter])
	{
	  curpos.x = 0;
	  while (curpos.x < pix->clipable.buffer.width)
	    {
	      curpos.y += cur_height;
	      tekpixel(pix, &curpos, color[counter]);
	      curpos.y -= cur_height;
	      curpos.x++;
	    }
	  curpos.y++;
	}
      counter++;
      cur_height += curpos.y;
    }
}
