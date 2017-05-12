/*
** bsq.h for bsq in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Dec 14 17:23:42 2015 Alexis Viguié
** Last update Mon Dec 21 15:08:27 2015 Alexis Viguié
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct	s_square
{
  t_coord	init_pos;
  int		size;
}		t_square;

int	get_row_number(char *filecontents);

char	*get_plat(char *filecontents, int row_number);

void	proc_plat(char *plat, int row_number);

void	exit_args(char *bin_name);
void	exit_file_not_found(char *filename);
void	exit_incorrect_file(char *filecontents);
void	exit_mllc();

#endif /* !BSQ_H_ */
