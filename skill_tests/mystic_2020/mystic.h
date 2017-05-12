/*
** mystic.h for mystic in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 11 10:32:28 2016 Alexis Viguié
** Last update Thu Feb 11 10:35:19 2016 Alexis Viguié
*/

#ifndef MYSTIC_H_
# define MYSTIC_H_

#include <lapin.h>

typedef struct		s_bunny_circle
{
  t_bunny_position	position;
  double		radius;
  unsigned int		color;
}			t_bunny_circle;

#endif /* !MYSTIC_H_ */
