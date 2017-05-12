/*
** 512.h for colle 3 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May 10 19:20:45 2016 Alexis Viguié
** Last update Tue May 10 22:51:14 2016 Stanislav HEURTAULT
*/

#ifndef GAME_512_H_
# define GAME_512_H_

# include <lapin.h>

# define WIDTH 256
# define HEIGHT 256
# define GRID_SIZE 4
# define WIDTH_FONT (10 * 64)
# define HEIGHT_FONT 64

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*font;
  t_bunny_position	pos;
  int			grid[GRID_SIZE][GRID_SIZE];
  bool			move;
}			t_data;

int		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos, t_color *color);
int		noise_color_full(t_bunny_pixelarray *pix, t_color *color);
unsigned int    getpixel(t_bunny_pixelarray *pix, t_bunny_position *pos);
int		load_grid(t_data *data);
int		init_data(t_data *data, int ac, char **av);

bool	check_if_moveable(int grid[GRID_SIZE][GRID_SIZE]);
bool	check_win(int grid[GRID_SIZE][GRID_SIZE]);

int     turn_right(t_data *data);
int     turn_left(t_data *data);
int     turn_up(t_data *data);
int     turn_down(t_data *data);

void    check_right(t_data *data, t_bunny_position pos, t_bunny_position check);
void    check_left(t_data *data, t_bunny_position pos, t_bunny_position check);
void    check_up(t_data *data, t_bunny_position pos, t_bunny_position check);
void    check_down(t_data *data, t_bunny_position pos, t_bunny_position check);

int     new_one(int grid[GRID_SIZE][GRID_SIZE]);
void	my_putstr(char *str, int fd);

# define MESSAGE_WIN "You won, congratulations!\n"
# define MESSAGE_LOSE "You lost, try again!\n"
# define MESSAGE_MAP "Bad map size\n"
# define MESSAGE_IMAGE "Bad image size\n"

#endif /* !GAME_512_H_ */
