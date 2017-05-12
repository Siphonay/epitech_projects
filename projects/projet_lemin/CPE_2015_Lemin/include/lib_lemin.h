/*
** lib_lemin.h for lib lemin in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Apr 14 14:39:04 2016 Alexis Viguié
** Last update Wed Apr 20 16:17:34 2016 Alexis Viguié
*/

#ifndef LIB_LEMIN_H_
# define LIB_LEMIN_H_

union		u_room_coord
{
  unsigned int	x;
  unsigned int	y;
};

typedef struct		s_room
{
  char			*name;
  union u_room_coord	coord;
  struct s_room		**next;
}			t_room;

# define FD_STDIN 0
# define FD_STDOUT 1
# define FD_STDERR 2

void		lemin_putstr(char *str, int fd);
unsigned int	lemin_strlen(char *str);
char		*lemin_getline();

void		free_all_rooms(t_room *start_room);
unsigned int	link_room(t_room *room, t_room *tolink_room);
t_room		*create_room(char *new_name, union u_room_coord new_coord);

#endif /* !LIB_LEMIN_H_ */
