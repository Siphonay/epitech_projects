/*
** main.c for test in /home/viguie_a/piscine_lapin
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Wed Oct 14 10:47:13 2015 Alexis Viguié
** Last update Mon Nov  2 22:06:46 2015 Alexis Vigui�
*/

#include <lapin.h>
#include "my_set_pixel.h"

int			main(int ac, char **av)
{
  t_bunny_window	*win = bunny_start(800, 600, false, "test");
  t_bunny_position	pos;

  pos.x = 42;
  pos.y = 42;
  bunny_my_set_pixel(&win->buffer, pos, );
  bunny_display(win);
  while (1);
  return (0);
}
