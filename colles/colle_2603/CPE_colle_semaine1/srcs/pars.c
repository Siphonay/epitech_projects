/*
** pars.c for CPE_colle_semaine1 in /home/simon/CPE_colle_semaine1/srcs
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 14:15:40 2016 Simon Pedrono
** Last update Tue Apr 26 17:58:03 2016 Simon Pedrono
*/

#include <unistd.h>
#include "tree.h"

t_options	my_checknb(t_options st, int nb)
{
  if (nb < 0)
    {
      st.level = -1;
      my_putstr_err("tree: Invalid level, must be greater than 0.\n");
    }
  else
    st.level = nb;
  return (st);
}

t_options	my_pars_L(char **av, t_options st)
{
  int	i;
  int	nb;

  i = 0;
  while (av[i] != NULL)
    {
      nb = -137;
      if (my_findletterL(av[i]))
	{
	  if (av[i + 1] != NULL)
	    {
	      i++;
	      nb = my_getnbr(av[i]);
	      st = my_checknb(st, nb);
	      nb = -1;
	    }
	  else
	    my_putstr_err("tree: Missing argument to -L option.\n");
	}
	i++;
    }
  return (st);
}

t_options	my_checkparam(t_options st, char c)
{
  if (c == '-')
    return (st);
  else if (c == 'a')
    st.all = 1;
  else if (c == 'd')
    st.dirs_only = 1;
  else if (c == 'L')
    st.level = -1;
  else if (c == 'f')
    st.fullpath = 1;
  else
    {
      if (st.usage == 0)
	st.bad = c;
      st.usage = 1;
    }
  return (st);
}

t_options	my_parser(char **av)
{
  int		i;
  int		j;
  char		c;
  t_options	st;

  st.usage = 0;
  i = 1;
  c = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] == '-' && av[i][1] != '\0')
        {
	  j = 0;
	  while (av[i][j] != '\0')
	    {
	      c = av[i][j];
	      st = my_checkparam(st, c);
              j++;
	    }
	}
      if (c == 'L' && av[i + 1] != NULL)
	i++;
      i++;
    }
  return (st);
}
