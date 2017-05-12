/*
** my_sh.c for my_sh in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 19:29:12 2016 thibault derbre
** Last update Tue Apr 12 14:58:51 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

t_data		*my_sh(t_data *data)
{
  char		*s;
  t_list	*lex;

  init_var(data);
  lex = NULL;
  while (42)
    {
      show_prompt(data);
      if ((s = get_next_line(0)) == NULL)
	break ;
      if ((lex = lex_pars(lex, data, s)) != NULL)
	launch_commands(data, lex);
      if (lex != NULL)
	my_list_free(lex, data);
      if (data->if_exit == 1)
	break ;
      free(s);
      lex = NULL;
    }
  if (s == NULL)
    my_putstr("exit\n");
  free(s);
  return (data);
}
