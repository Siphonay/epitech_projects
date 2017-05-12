/*
** tree.h for  in /home/simon/colle_1_2603/include
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 14:09:55 2016 Simon Pedrono
** Last update Tue Apr 26 17:58:48 2016 Simon Pedrono
*/

#ifndef TREE_H_
# define TREE_H_

# include <stdbool.h>

typedef struct	s_options
{
  bool		all;
  bool		dirs_only;
  int		level;
  bool		fullpath;
  bool		usage;
  char		bad;
}		t_options;

typedef struct	s_num
{
  int		file_num;
  int		dir_num;
}		t_num;

int		my_getnbr(char *str);
void		my_putstr(char *str);
void		my_putstr_err(char *str);
t_options	my_checkparam(t_options st, char c);
t_options	my_parser(char **av);
void		my_putchar_err(char c);
void		print_usage(t_options st);
void		disp_tree(char **av, t_options options);
t_options	my_pars_L(char **av, t_options st);
int		my_isnum(char *str);
int		my_findletterL(char *str);
void		my_putchar(char c);
void		my_putnbr(int nb);
int		my_strcmp(char *str, char *str2);
t_num		disp_dir(char *dir_name, int depth,
			 t_options options, t_num elems);

# define HORIZONTAL_LINE "-"
# define VERTICAL_LINE "|"
# define ANGLE "`"

#endif /* !TREE_H_ */
