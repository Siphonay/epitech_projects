/*
** check.c for 512 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
**
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
**
** Started on  Tue May 10 21:10:51 2016 Stanislav HEURTAULT
** Last update Tue May 10 22:59:14 2016 Alexis Viguié
*/

#include <lapin.h>
#include <stdio.h>
#include "game_512.h"

void	check_right(t_data *data, t_bunny_position pos, t_bunny_position check)
{
  while (check.x < GRID_SIZE && data->grid[check.y][check.x] == 0)
    check.x++;
  if (check.x == GRID_SIZE)
    {
      data->grid[check.y][check.x - 1] = data->grid[pos.y][pos.x];
      if (check.x - 1 != pos.x)
	data->move = !(data->grid[pos.y][pos.x] = 0);
    }
  else if (data->grid[check.y][check.x] == data->grid[pos.y][pos.x])
    {
      data->grid[check.y][check.x] += 1;
      data->grid[pos.y][pos.x] = 0;
      data->move = true;
    }
  else
    {
      data->grid[check.y][check.x - 1] = data->grid[pos.y][pos.x];
      if (check.x - 1 != pos.x)
	{
	  data->grid[pos.y][pos.x] = 0;
	  data->move = true;
	}
    }
}

void	check_left(t_data *data, t_bunny_position pos, t_bunny_position check)
{
  while (check.x >= 0 && data->grid[check.y][check.x] == 0)
    check.x--;
  if (check.x < 0)
    {
      data->grid[check.y][check.x + 1] = data->grid[pos.y][pos.x];
      if (check.x + 1 != pos.x)
	data->move = !(data->grid[pos.y][pos.x] = 0);
    }
  else if (data->grid[check.y][check.x] == data->grid[pos.y][pos.x])
    {
      data->grid[check.y][check.x] += 1;
      data->grid[pos.y][pos.x] = 0;
      data->move = true;
    }
  else
    {
      data->grid[check.y][check.x + 1] = data->grid[pos.y][pos.x];
      if (check.x + 1 != pos.x)
	{
	  data->grid[pos.y][pos.x] = 0;
	  data->move = true;
	}
    }
}

void	check_up(t_data *data, t_bunny_position pos, t_bunny_position check)
{
  while (check.y >= 0 && data->grid[check.y][check.x] == 0)
    check.y--;
  if (check.y < 0)
    {
      data->grid[check.y + 1][check.x] = data->grid[pos.y][pos.x];
      if (check.y + 1 != pos.y)
	data->move = !(data->grid[pos.y][pos.x] = 0);
    }
  else if (data->grid[check.y][check.x] == data->grid[pos.y][pos.x])
    {
      data->grid[check.y][check.x] += 1;
      data->grid[pos.y][pos.x] = 0;
      data->move = true;
    }
  else
    {
      data->grid[check.y + 1][check.x] = data->grid[pos.y][pos.x];
      if (check.y + 1 != pos.y)
	{
	  data->grid[pos.y][pos.x] = 0;
	  data->move = true;
	}
    }
}

void	check_down(t_data *data, t_bunny_position pos, t_bunny_position check)
{
  while (check.y < GRID_SIZE && data->grid[check.y][check.x] == 0)
    check.y++;
  if (check.y == GRID_SIZE)
    {
      data->grid[check.y - 1][check.x] = data->grid[pos.y][pos.x];
      if (check.y-+ 1 != pos.y)
	data->move = !(data->grid[pos.y][pos.x] = 0);
    }
  else if (data->grid[check.y][check.x] == data->grid[pos.y][pos.x])
    {
      data->grid[check.y][check.x] += 1;
      data->grid[pos.y][pos.x] = 0;
      data->move = true;
    }
  else
    {
      data->grid[check.y - 1][check.x] = data->grid[pos.y][pos.x];
      if (check.y - 1 != pos.y)
	{
	  data->grid[pos.y][pos.x] = 0;
	  data->move = true;
	}
    }
}
