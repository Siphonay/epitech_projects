/*
** game_512_fncs.c for colle 3 in /home/sam/Rendu/Colles/colle_s3/CPE_colle_semaine3/src
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May 10 19:30:26 2016 Alexis Viguié
** Last update Tue May 10 22:40:13 2016 Alexis Viguié
*/

#include <stdbool.h>
#include "game_512.h"

bool	check_if_moveable(int grid[GRID_SIZE][GRID_SIZE])
{
  int	counter;
  int	counter2;
  int	cur_case;

  counter = 0;
  while (counter < GRID_SIZE)
    {
      counter2 = 0;
      while (counter2 < GRID_SIZE)
	{
	  if (!(cur_case = grid[counter][counter2]) ||
	      (counter && grid[counter - 1][counter2] == cur_case) ||
	      (counter2 && grid[counter][counter2 - 1] == cur_case) ||
	      (counter != (GRID_SIZE - 1) &&
	       grid[counter + 1][counter2] == cur_case) ||
	      (counter2 != (GRID_SIZE - 1) &&
	       grid[counter][counter2 + 1] == cur_case))
	    return (true);
	  counter2++;
	}
      counter++;
    }
  return (false);
}

bool	check_win(int grid[GRID_SIZE][GRID_SIZE])
{
  int	counter;
  int	counter2;

  counter = 0;
  while (counter < GRID_SIZE)
    {
      counter2 = 0;
      while (counter2 < GRID_SIZE)
	{
	  if (grid[counter][counter2] == 9)
	    return (true);
	  counter2++;
	}
      counter++;
    }
  return (false);
}
