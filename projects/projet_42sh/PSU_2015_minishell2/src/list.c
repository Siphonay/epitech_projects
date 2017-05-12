/*
** list.c for list in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 11:53:36 2016 thibault derbre
** Last update Sat Apr  9 17:10:16 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	my_list_free(t_list *lex, t_data *data)
{
  t_list *tmp;

  tmp = lex;
  free_char_table(data->args);
  free(data->command);
  free(data->path);
  free(data->full_cmd);
  while (lex->next != NULL)
    {
      tmp = lex;
      lex = lex->next;
      free_char_table(tmp->args);
      free(tmp);
    }
  free(lex);
}

t_list	*fill_elem(t_list *elem, char *str, t_data *data)
{
  data->nb_cmd++;
  elem->cmd = str;
  if ((my_strcmp(str, "|")) == 0)
    {
      elem->id = 1;
      elem->is_piped = 1;
    }
  else if ((my_strcmp(str, ">")) == 0)
    elem->id = 2;
  else if ((my_strcmp(str, ">>")) == 0)
    elem->id = 3;
  else if ((my_strcmp(str, "<")) == 0)
    elem->id = 4;
  else if ((my_strcmp(str, "<<")) == 0)
    elem->id = 5;
  else if ((my_strcmp(str, ";")) == 0)
    elem->id = 6;
  else
    {
      elem->args = str_to_wordtab(str);
      elem->id = 0;
    }
  return (elem);
}

t_list	*my_put_in_list(t_list *lex, char *str, t_data *data)
{
  t_list        *elem;
  t_list        *tmp;

  elem = NULL;
  if (lex == NULL)
    {
      if ((elem = malloc(sizeof(*elem))) == NULL)
	exit (-1);
      elem->next = NULL;
      elem->prev = NULL;
      elem = fill_elem(elem, str, data);
      return (elem);
    }
  if ((elem = malloc(sizeof(*elem))) == NULL)
    exit (-1);
  tmp = lex;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  elem->next = NULL;
  elem = fill_elem(elem, str, data);
  return (lex);
}
