/*
** main.c for main in /home/herlin_a/rendu/gfx_incendie
**
** Made by Victor Herlin
** Login   <herlin_a@epitech.net>
**
** Started on  Sat Dec  5 09:23:45 2015 Victor Herlin
** Last update Sun Dec  6 16:56:47 2015 Alexis Viguié
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <stdlib.h>
#include <stdio.h>
#include "incendie.h"

void    my_set_pixel(t_bunny_pixelarray *pix, t_bunny_position *pos, unsigned int color)
{
  int   i;
  int   *pixel;

  i = ((pix->clipable.buffer.width) * (pos->y + 1)) + pos->x;
  pixel = pix -> pixels;
  pixel[i] = color;
}

int     affichage(const t_bunny_window *win)
{
  bunny_display(win);
  return (GO_ON);
}

int     main()
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *pix;
  t_bunny_position      pos;
  int   i;
  int   ret;
  void  *ptr_fct;
  int   x2;
  int   y2;
  int	*cpal;

  ptr_fct = &(affichage);
  i = 0;
  win = bunny_start(1000, 1000, false, "lapinou");
  pix = bunny_new_pixelarray(1000, 1000);
  pos.y = 0;
  cpal = gen_palette();
  while (pos.y < 1000)
    {
      pos.x = 0;
      while (pos.x < 1000)
	{
	  my_set_pixel(pix, &pos, cpal[i]);
	  pos.x++;
	}
      pos.y++;
      if (pos.y > 873)
	i++;
    }
  bunny_blit(&win->buffer, &pix->clipable, &pos);
  bunny_set_loop_main_function(ptr_fct);
  bunny_loop(win, 10, win);
  bunny_delete_clipable(&pix->clipable);
  bunny_free(win);
  bunny_stop(win);
}
