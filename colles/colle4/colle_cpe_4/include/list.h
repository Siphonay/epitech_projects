/*
** list.h for my transformer in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 09:51:08 2015 Alexis Viguié
** Last update Fri Dec 18 10:32:32 2015 Alexis Viguié
*/

#ifndef LIST_H_
# define LIST_H_
typedef struct	s_list
{
  char		*data;
  struct s_list *next;
  struct s_list *prev;
}		t_list;

void	put_last_char(char *str);
void	last_char(t_list *list);
void	my_push_back(t_list **list, char *data);
void	my_push_front(t_list **begin, char *data);
void	list_swap(t_list **list, t_list *first, t_list *second);
void	my_alpha_sort(t_list *list);
#endif /* !LIST_H_ */
