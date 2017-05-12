/*
** init_list.c for init_list in /home/zaza/rendu/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed May 11 18:03:03 2016 thibault derbre
** Last update	Sun Jun 05 18:11:50 2016 pedron_s
*/

#include <stdlib.h>
#include "liste.h"
#include "mysh.h"

t_list		init_list(t_data *data, char *str)
{
  t_list	liste;

  (void)data;
  liste.check = 0;
  if ((str = epur_str(str)) == NULL)
    {
      liste.check = -1;
      return (liste);
    }
  if ((str = delete_token_spaces(str)) == NULL)
    {
     liste.check = -1;
     return (liste);
    }
  if ((my_list(str, &liste)) != 0)
    {
      liste.check = -1;
      return (liste);
    }
  return (liste);
}
