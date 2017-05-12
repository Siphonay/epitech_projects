/*
** poker.h for my poker in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Dec 10 14:04:28 2015 Alexis Viguié
** Last update Thu Dec 10 15:47:38 2015 Alexis Viguié
*/

#ifndef POKER_H_
# define POKER_H_
typedef struct	s_list
{
  char		*name;
  int		dealer;
  struct	s_list *next;
  struct	s_list *prec;
}		t_list;
void    list_push_front(t_list **list, char *str);
void    list_push_back(t_list **list, char *str, char *last);
void    aff_list(t_list **list);
void    turn_dealer(t_list **list);
void    delete_list(t_list **list, char *str);
void	my_putstr(char *str);
void	my_putstr_err(char *str);
void	player_operations(t_list *players, char *op);
void	process_operation(t_list *players, char *op);
int	my_strcmp(char *s1, char *s2);
#endif /* POKER_H_ */
