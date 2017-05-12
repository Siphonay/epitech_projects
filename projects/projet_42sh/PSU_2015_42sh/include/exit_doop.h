/*
** exit_doop.h for 42sh in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May 31 15:42:08 2016 Alexis Viguié
** Last update Tue May 31 20:44:34 2016 Alexis Viguié
*/

#ifndef EXIT_DOOP_H_
# define EXIT_DOOP_H_

# include <stdbool.h>

typedef struct	s_exitval
{
  int		value;
  bool		is_valid;
}		t_exitval;

# define OP_PLUS "+"
# define OP_MINUS "-"
# define OP_TIMES "*"
# define OP_DIVIDE "/"
# define OP_MODULO "%"

t_exitval	exit_doop(char **ops);

# endif /* !EXIT_DOOP_H_ */
