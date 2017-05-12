/*
** last_char.c for last_char in /home/nwoumg_d/rendu/colle_cpe_4
**
** Made by nwoumg_d
** Login   <nwoumg_d@epitech.net>
**
** Started on  Fri Dec 18 09:43:01 2015 nwoumg_d
** Last update Fri Dec 18 10:10:21 2015 Alexis Viguié
*/

#include <unistd.h>
#include "list.h"

void	put_last_char(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  i--;
  write(1, &str[i], 1);
}

void		last_char(t_list *list)
{
  t_list        *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      put_last_char(tmp->data);
      tmp = tmp->next;
    }
}
