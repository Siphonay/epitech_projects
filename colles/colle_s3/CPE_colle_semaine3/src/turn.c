/*
** turn.c for 512 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
** 
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
** 
** Started on  Tue May 10 20:50:55 2016 Stanislav HEURTAULT
** Last update Tue May 10 22:11:48 2016 Stanislav HEURTAULT
*/

#include <lapin.h>
#include "game_512.h"

int	turn_right(t_data *data)
{
  t_bunny_position	pos;
  t_bunny_position	check;

  pos.y = 0;
  while (pos.y < GRID_SIZE)
    {
      pos.x = GRID_SIZE - 1;
      check.y = pos.y;
      while (pos.x >= 0)
	{
	  check.x = pos.x + 1;
	  if (data->grid[pos.y][pos.x] != 0)
	    check_right(data, pos, check);
	  pos.x--;
	}
      pos.y++;
    }
  return (0);
}

int	turn_left(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      check;

  pos.y = 0;
  while (pos.y < GRID_SIZE)
    {
      pos.x = 0;
      check.y = pos.y;
      while (pos.x < GRID_SIZE)
        {
          check.x = pos.x - 1;
	  if (data->grid[pos.y][pos.x] != 0)
	    check_left(data, pos, check);
          pos.x++;
        }
      pos.y++;
    }
  return (0);
}

int	turn_down(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      check;

  pos.x = 0;
  while (pos.x < GRID_SIZE)
    {
      pos.y = GRID_SIZE - 1;
      check.x = pos.x;
      while (pos.y >= 0)
        {
          check.y = pos.y + 1;
	  if (data->grid[pos.y][pos.x] != 0)
	    check_down(data, pos, check);
	  pos.y--;
        }
      pos.x++;
    }
  return (0);
}

int	turn_up(t_data *data)
{
  t_bunny_position      pos;
  t_bunny_position      check;

  pos.x = 0;
  while (pos.x < GRID_SIZE)
    {
      pos.y = 0;
      check.x = pos.x;
      while (pos.y < GRID_SIZE)
        {
          check.y = pos.y - 1;
	  if (data->grid[pos.y][pos.x] != 0)
	    check_up(data, pos, check);
	  pos.y++;
        }
      pos.x++;
    }
  return (0);
}

