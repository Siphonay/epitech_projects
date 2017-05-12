/*
** add_random.c for 512 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
**
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
**
** Started on  Tue May 10 21:37:20 2016 Stanislav HEURTAULT
** Last update Tue May 10 22:49:46 2016 Stanislav HEURTAULT
*/

#include <unistd.h>
#include <lapin.h>
#include "game_512.h"

t_bunny_position	new_place()
{
  t_bunny_position	random;

  random.x = rand() % GRID_SIZE;
  random.y = rand() % GRID_SIZE;
  return (random);
}

int	is_used(int grid[GRID_SIZE][GRID_SIZE], t_bunny_position random)
{
  if (grid[random.y][random.x] != 0)
    return (1);
  return (0);
}

t_bunny_position	change_pos(t_bunny_position random, int *ret)
{
  int	i;

  i = *ret;
  if ((random.y + 1) % GRID_SIZE == 0)
    {
      random.y = 0;
      if ((random.x + 1) % GRID_SIZE == 0)
	{
	  random.x = 0;
	  i++;
	}
      else
	random.x++;
    }
  else
    random.y++;
  *ret = i;
  return (random);
}

int	new_one(int grid[GRID_SIZE][GRID_SIZE])
{
  t_bunny_position	random;
  int			ret;

  random = new_place();
  ret = 0;
  while (is_used(grid, random) != 0 && ret < 2)
    random = change_pos(random, &ret);
  if (ret == 2)
    return (1);
  grid[random.y][random.x] = rand() % 4;
  if (grid[random.y][random.x] == 3)
    grid[random.y][random.x] = 2;
  else
    grid[random.y][random.x] = 1;
  return (0);
}
