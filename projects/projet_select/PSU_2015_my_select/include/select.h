/*
** select.h for my select in /home/sam/projet_select/PSU_2015_my_select/include
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Dec 13 19:53:18 2015 Alexis Viguié
** Last update Sun Dec 13 23:40:15 2015 Alexis Viguié
*/

#include <ncurses.h>
#ifndef SELECT_H_
# define SELECT_H_
void	print_select_exit(char **args, int *index, int ac);
void	arg_err(char **av);
void	mllc_err();
void	wsize_err();
int	*build_ncpos_base();
int	*update_ncpos(int *ncpos, int *wsize);
void	setattr(int pos, int index, int counter);
int	*ncprint_curpos(WINDOW *ncwin, int *ncpos, char *elem);
int	pos_update(char **elems, int pos, int counter);
#endif /* SELECT_H_ */
