/*
** init.c for 512 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
** 
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
** 
** Started on  Tue May 10 20:44:09 2016 Stanislav HEURTAULT
** Last update Tue May 10 22:28:10 2016 Stanislav HEURTAULT
*/

#include <lapin.h>
#include <unistd.h>
#include "game_512.h"

void    init_grid(t_data *data)
{
  t_bunny_position      pos;

  pos.y = 0;
  while (pos.y < GRID_SIZE)
    {
      pos.x= 0;
      while (pos.x < GRID_SIZE)
        {
          data->grid[pos.y][pos.x] = 0;
          pos.x++;
        }
      pos.y++;
    }
}

void    init_random(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      ret;

  srand(getpid());
  pos.x = rand() % 4;
  pos.y = rand() % 4;
  data->grid[pos.y][pos.x] = 1;
  ret.x= rand() % 4;
  ret.y = rand() % 4;
  if (ret.y == pos.y && ret.x == pos.x)
    ret.y = (ret.y + 1) % 4;
  data->grid[ret.y][ret.x] = 1;
}

int     init_data(t_data *data, int ac, char **av)
{
  t_color       black;

  if ((data->win = bunny_start(WIDTH, HEIGHT, 0, "512")) == NULL)
    return (1);
  if ((data->pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  black.full = BLACK;
  noise_color_full(data->pix, &black);
  if (ac < 2)
    {
      write(2, "No image given as parameter\n" , 28);
      return (1);
    }
  else
    {
      if ((data->font = bunny_load_pixelarray(av[1])) == NULL)
	return (1);
    }
  data->pos.x = 0;
  data->pos.y = 0;
  data->move = 0;
  init_grid(data);
  init_random(data);
  return (0);
}
