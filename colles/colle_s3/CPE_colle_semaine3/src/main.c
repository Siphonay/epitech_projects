/*
** main.c for 512 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
**
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
**
** Started on  Tue May 10 19:17:04 2016 Stanislav HEURTAULT
** Last update Tue May 10 22:51:39 2016 Stanislav HEURTAULT
*/

#include <lapin.h>
#include <unistd.h>
#include "game_512.h"

int	check_end(int grid[GRID_SIZE][GRID_SIZE])
{
  if (!check_if_moveable(grid))
    {
      my_putstr(MESSAGE_LOSE, 1);
      return (1);
    }
  else if (check_win(grid))
    {
      my_putstr(MESSAGE_WIN, 1);
      return (1);
    }
  return (0);
}

t_bunny_response	key_response(t_bunny_event_state	state,
				     t_bunny_keysym		key,
				     void			*your_data)
{
  t_data	*data;

  data = your_data;
  data->move = false;
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (key == BKS_RIGHT)
	turn_right(data);
      if (key == BKS_LEFT)
	turn_left(data);
      if (key == BKS_UP)
	turn_up(data);
      if (key == BKS_DOWN)
	turn_down(data);
      if (data->move)
	if (new_one(data->grid))
	  return (EXIT_ON_ERROR);
    }
  return (GO_ON);
}

t_bunny_response	mainloop(void *your_data)
{
  t_data	*data;

  data = your_data;
  if (check_end(data->grid))
    return (EXIT_ON_SUCCESS);
  bunny_set_key_response(key_response);
  load_grid(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, &data->pos);
  bunny_display(data->win);
  return (GO_ON);
}

int	check_size(t_data *data)
{
  if (data->pix->clipable.clip_width != WIDTH)
    {
      my_putstr(MESSAGE_MAP, 2);
      return (1);
    }
  if (data->pix->clipable.clip_height != HEIGHT)
    {
      my_putstr(MESSAGE_MAP, 2);
      return (1);
    }
  if (data->font->clipable.clip_width != WIDTH_FONT)
    {
      my_putstr(MESSAGE_IMAGE, 2);
      return (1);
    }
  if (data->font->clipable.clip_height != HEIGHT_FONT)
    {
      my_putstr(MESSAGE_IMAGE, 2);
      return (1);
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_data		data;

  if (init_data(&data, ac, av) != 0)
    return (1);
  if (check_size(&data) != 0)
    return (1);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, 60, &data);
  bunny_delete_clipable(&data.pix->clipable);
  bunny_stop(data.win);
  return (0);
}
