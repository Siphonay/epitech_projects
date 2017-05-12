/*
** main.c for my transformer in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 09:33:09 2015 Alexis Viguié
** Last update Fri Dec 18 10:53:35 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "transformer.h"
#include "list.h"

void		aff_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      tmp = tmp->next;
      write(1, "\n", 1);
    }
}

int		main(int ac, char **av)
{
  t_list	*main_list;
  char		*rev_arg;
  int		counter;

  main_list = NULL;
  if (ac != 2)
    {
      my_putstr_err("please use ONE string as argument\n");
      return (1);
    }
  if (my_is_alpha(av[1]) == 0)
    {
      my_putstr_err("invalid argument\n");
      return (1);
    }
  rev_arg = av[1];
  my_push_front(&main_list, rev_arg);
  counter = 0;
  while (counter < my_strlen(av[1]))
    {
      rev_arg = my_str_rotation(rev_arg);
      my_push_back(&main_list, rev_arg);
      counter++;
    }
  free(rev_arg);
  aff_list(main_list);
}
