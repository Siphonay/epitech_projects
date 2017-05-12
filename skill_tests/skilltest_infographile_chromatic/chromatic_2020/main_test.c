/*
** main_test.c for main test in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Feb  3 16:23:22 2016 Alexis Viguié
** Last update Thu Feb 11 09:47:48 2016 Alexis Viguié
*/

#include <lapin.h>

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 unsigned int color);

void   	c64_chromatic(t_bunny_pixelarray *pix,
		      unsigned int	*height,
		      unsigned int	*color,
		      size_t		len);

int	disp_fnc(const t_bunny_window *win)
{
  bunny_display(win);
  return (GO_ON);
}

int			main()
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	fullblit;
  void			*ptr_fct;
  static unsigned int	height[5] = {33, 33, 33, 33, 348};
  static unsigned int	color[5] = {RED, BLACK, RED, BLACK, WHITE};

  ptr_fct = &(disp_fnc);
  win = bunny_start(640, 480, false, "TEKPIXEL TEST");
  pix = bunny_new_pixelarray(640, 480);
  c64_chromatic(pix, height, color, 5);
  fullblit.x = 0;
  fullblit.y = 0;
  bunny_blit(&win->buffer, &pix->clipable, &fullblit);
  bunny_set_loop_main_function(ptr_fct);
  bunny_loop(win, 60, win);
  bunny_delete_clipable(&pix->clipable);
  bunny_free(win);
  bunny_stop(win);
}
