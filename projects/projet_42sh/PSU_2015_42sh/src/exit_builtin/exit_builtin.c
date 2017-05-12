/*
** exit_builtin.c for 42sh in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May 31 17:21:14 2016 Alexis Viguié
** Last update Sun Jun  5 22:15:54 2016 Alexis Viguié
*/

#include <stdlib.h>
#include "liste.h"
#include "mysh.h"
#include "exit_doop.h"

void	free_wordtab(char **wordtab)
{
  int	counter;

  counter = 0;
  while (wordtab[counter])
    {
      free(wordtab[counter]);
      counter++;
    }
  free(wordtab);
}

void	get_free_file(t_data *data)
{
  int	i;
  int	j;

  i = 0;
  if (data->file[0].param != NULL)
    {
      while (data->file[i].param != NULL)
	{
	  j = 0;
	  while (data->file[i].tab[j] != NULL)
	    {
	      free(data->file[i].tab[j]);
	      j++;
	    }
	  free(data->file[i].tab);
	  free(data->file[i].param);
	  i++;
	}
      free(data->file);
  }
}

void		exit_builtin(t_elem *elems, char **av,
			     char **env_vars, t_data *data)
{
  t_exitval		exit_value;

  if (!av[1])
    {
      exit_value.value = 0;
      exit_value.is_valid = true;
    }
  else
    exit_value = exit_doop(&av[1]);
  if (!exit_value.is_valid)
    return ;
  while (elems->pos && elems->prev)
    elems = elems->prev;
  while (elems)
    {
      free_wordtab(elems->cmd);
      if (elems->pos)
	free(elems->prev);
      elems = elems->next;
    }
  free(elems);
  free_wordtab(env_vars);
  get_free_file(data);
  exit(exit_value.value);
}
