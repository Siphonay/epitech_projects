/*
** lemin_ll_fnc.c for lib lemin in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Apr 14 14:45:06 2016 Alexis Viguié
** Last update Thu Apr 21 15:50:15 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "lib_lemin.h"

t_room		**create_empty_next_room()
{
  t_room	**ret_empty_room;

  if (!(ret_empty_room = malloc(sizeof(t_room*))))
    return (NULL);
  ret_empty_room[0] = NULL;
  return (ret_empty_room);
}

t_room		*create_room(char *new_name, union u_room_coord new_coord)
{
  t_room	*ret_room;

  if ((ret_room = malloc(sizeof(t_room))) == NULL)
    return (NULL);
  ret_room->name = new_name;
  ret_room->coord = new_coord;
  if (!(ret_room->next = create_empty_next_room()))
    return (NULL);
  return (ret_room);
}

unsigned int	link_room(t_room *room, t_room *tolink_room)
{
  unsigned int	counter;
  t_room	**new_room_pointer;

  counter = 0;
  while (room->next[counter])
    counter++;
  if (!(new_room_pointer = malloc(sizeof(t_room*) * (counter + 1))))
      return (1);
  new_room_pointer[counter + 1] = NULL;
  counter = 0;
  while (room->next[counter])
    {
      new_room_pointer[counter] = room->next[counter];
      counter++;
    }
  new_room_pointer[counter] = tolink_room;
  free(room->next);
  room->next = new_room_pointer;
  return (0);
}

void		free_all_rooms(t_room *start_room)
{
  unsigned int	counter;

  counter = 0;
  while (start_room->next[counter])
    {
      free(start_room->next[counter]);
      start_room->next[counter] = NULL;
      counter++;
      if (start_room->next[counter])
	free_all_rooms(start_room->next[counter]);
    }
  free(start_room->next);
  start_room->next = NULL;
}
