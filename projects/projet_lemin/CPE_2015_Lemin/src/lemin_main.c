/*
** lemin_main.c for lemin in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Apr 20 17:19:00 2016 Alexis Viguié
** Last update Thu Apr 21 15:51:51 2016 Alexis Viguié
*/

#include "lib_lemin.h"
/* DEBUG */ #include <stdio.h>

int			main(void)
{
  union u_room_coord	coord;
  t_room		*room;
  t_room		*room2;
  t_room		*room3;

  coord.x = 7;
  coord.y = 2;
  if (!(room = create_room("batman", coord)))
    return (42);
  coord.x = 9;
  coord.y = 4;
  if (!(room2 = create_room("superman", coord)))
    return (84);
  coord.x = 66;
  coord.y = 1;
  if (!(room3 = create_room("birdman", coord)))
    return (128);
  if ((link_room(room, room2)) || (link_room(room2, room)) ||
      (link_room(room, room3)))
    return (74);
  printf("%s is linked to %s and %s.\n",
	 room->name, room->next[0]->name, room->next[1]->name);
  free_all_rooms(room);
 return (0);
}
