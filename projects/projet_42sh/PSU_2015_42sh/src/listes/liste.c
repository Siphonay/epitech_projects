/*
** liste.c for newls!
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Wed May 25 10:50:04 2016 pedron_s
** Last update	Sun Jun 05 22:11:47 2016 pedron_s
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"
#include "mysh.h"

int	my_check_id(t_elem *elem)
{
  int	i;

  i = 0;
  while (elem->cmd[i] != NULL)
    {
      if (strcmp(elem->cmd[i], "<") == 0)
	elem->id = SCHEI;
      else if (strcmp(elem->cmd[i], ">>") == 0)
	elem->id = DCHEO;
      else if (strcmp(elem->cmd[i], ">") == 0)
  	elem->id = SCHEO;
      else if (strcmp(elem->cmd[i], "&&") == 0)
  	elem->id = ISAND;
      else if (strcmp(elem->cmd[i], "||") == 0)
  	elem->id = ISOR;
      else if (strcmp(elem->cmd[i], "|") == 0)
  	elem->id = SPIPE;
      else if (strcmp(elem->cmd[i], ";") == 0)
  	elem->id = COL;
      i++;
    }
  return (0);
}

t_elem	*my_new_list(t_list *liste, int nb, char **tab, int i)
{
  int		val;
  t_elem	*elem;

  val = 0;
  nb < 1 ? nb = 1 : 0;
  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (elem);
  if ((elem->cmd = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  while (val < nb)
    elem->cmd[val++] = tab[i++];
  elem->cmd[val] = NULL;
  elem->pos = liste->size;
  liste->size += 1;
  return (elem);
}

int	add_list(t_list *liste, int nb, char **tab, int i)
{
  t_elem	*elem;

  if (liste->size != 0)
    {
      elem = liste->last;
      if (tab[i][0] == elem->cmd[0][0]
	  && (!(elem->cmd[0][0] >= 'a' && elem->cmd[0][0] <= 'z')))
	elem = my_addtolist(elem);
      else
	if ((elem = my_new_list(liste, nb, tab, i)) == NULL)
	  return (-1);
    }
  else
    {
      if ((elem = my_new_list(liste, nb, tab, i)) == NULL)
	return (-1);
    }
  elem->prev = liste->last;
  liste->last ? liste->last->next = elem : 0;
  liste->first == NULL ? liste->first = elem : 0;
  elem->next = NULL;
  elem->id = 0;
  liste->last = elem;
  return (0);
}

int	my_count_linechar(char **tab, char *def, int i)
{
  int	nb;
  int	val;

  nb = 0;
  if (i > 0)
    {
      if ((my_check(tab[i], def)) == 1)
	return (1);
    }
  while (tab[i] != NULL)
    {
      val = 0;
      while (def[val] != '\0')
	{
	  if (tab[i] != NULL && tab[i][0] == def[val])
	    return (nb);
	  val++;
	}
      nb++;
      i++;
    }
  return (nb);
}

int		my_list(char *str, t_list *liste)
{
  int		i;
  int		nb;
  char		*def;
  char		**tabinput;

  i = 0;
  def = NULL;
  if (((def = malloc_def(def)) == NULL)
      || ((tabinput = my_str_to_wordtab(str, def, 0, 0)) == NULL))
      return (12);
  initialisation_liste(liste);
  while (tabinput[i] != NULL)
    {
      nb = 0;
      if (tabinput[i][0] == 0)
	tabinput[i] = NULL;
      else
	{
	  nb = my_count_linechar(tabinput, def, i);
	  add_list(liste, nb, tabinput, i);
	}
      nb > 0 ? i = i + nb : i++;
    }
  show_pos(liste, def);
  return (0);
}
