/*
** checkers.h for Red Alers in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Tue Mar 15 09:23:24 2016 Alexis Viguié
** Last update Tue Mar 15 09:51:09 2016 Alexis Viguié
*/

#ifndef CHECKERS_H_
# define CHECKERS_H_

#include <lapin.h>

typedef struct	s_bunny_size
{
  int		x;
  int		y;
}	       	t_bunny_size;

typedef struct		s_bunny_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  t_bunny_size		size;
}			t_bunny_data;

unsigned int	checkers_setcheckers(t_bunny_data *check_data);

# define CHECKERS_SIZE 8

#endif /* !CHECKERS_H_ */
