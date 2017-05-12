/*
** liste.h for PSU_2015_42sh
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Wed May 25 10:52:26 2016 pedron_s
** Last update	Sun Jun 05 22:11:49 2016 pedron_s
*/

#ifndef _LISTE_H_
# define _LISTE_H_

# define COMMAND 0
# define SPIPE 1
# define ISOR 2
# define SCHEO 3
# define DCHEO 4
# define SCHEI 5
# define COL 6
# define ISAND 7

typedef	struct	s_list
{
  int		size;
  int		check;
  struct s_elem	*first;
  struct s_elem *last;
  struct s_elem *temp;
}		t_list;

typedef struct s_elem
{
  int		pos;
  int		id;
  char		**cmd;
  struct s_elem *next;
  struct s_elem *prev;
}               t_elem;

int	my_count_linechar(char **tab, char *def, int i);
int	my_check(char *tab, char *def);
t_elem	*my_addtolist(t_elem *elem);
void	show_pos(t_list *liste, char *def);
int	add_list(t_list *liste, int nb, char **tab, int i);
int	my_check_id(t_elem *elem);
void	initialisation_liste(t_list *liste);
char	*malloc_def(char *def);
char    *my_mem_set2(char *str, int size);
int     my_count_line(char *str, char *def);
char	*my_opvals(char *tab, char *str, char def, int nb);
char	**my_malloc(int nb_line);
char    **my_str_to_wordtab(char *str, char *def, int i, int k);
int	my_freechain(t_list *liste);

#endif
