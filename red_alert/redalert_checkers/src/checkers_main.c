/*
** checkers_main.c for Red Alert in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Tue Mar 15 09:14:28 2016 Alexis Viguié
** Last update Tue Mar 15 10:02:42 2016 Alexis Viguié
*/

#include <lapin.h>
#include <stdlib.h>
#include "checkers.h"

t_bunny_loop	checkers_loop_fnc(t_bunny_data *check_data)
{
  if (checkers_setcheckers(check_data))
    return (NULL);
  bunny_display(check_data->win);
  bunny_blit(&check_data->win->buffer,
	     &check_data->pix->clipable,
	     &check_data->pos);
  return ((t_bunny_loop)GO_ON);
}

int		main(int ac, char **av)
{
  t_bunny_data	check_data;

  if (ac != 3)
    return (1);
  if (!(check_data.size.x = atoi(av[1])) || !(check_data.size.y = atoi(av[2])))
    return (1);
  check_data.win =
    bunny_start(check_data.size.x, check_data.size.y,
		false, "RED ALERT: Checkers");
  check_data.pix = bunny_new_pixelarray(check_data.size.x, check_data.size.y);
  check_data.pos.x = (check_data.pos.y = 0);
  bunny_set_loop_main_function((t_bunny_loop)checkers_loop_fnc);
  bunny_loop(check_data.win, 60, &check_data);
  bunny_delete_clipable(&check_data.pix->clipable);
  bunny_stop(check_data.win);
  return (0);
}
