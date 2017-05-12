/*
** alias3.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/conf_file/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Sat Jun  4 22:06:10 2016 Nolann Méléard
** Last update Sat Jun  4 23:13:24 2016 Nolann Méléard
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mysh.h"

t_file		*first_init_file()
{
  t_file	*file;

  if ((file = malloc(1 * sizeof(t_file))) == NULL)
    return (NULL);
  file[0].param = NULL;
  file[0].tab = NULL;
  return (file);
}

t_file	*count_and_realloc_file(t_file *file, int *j)
{
  int	i;

  i = 0;
  if (file[i].param != NULL)
    while (file[i].param != NULL)
	i++;
  if ((file = realloc(file, ((size_t) i + 2) * sizeof(t_file))) == NULL)
    return (NULL);
      file[i].param = NULL;
      file[i + 1].param = NULL;
      file[i].tab = NULL;
      file[i + 1].tab = NULL;
      *j = i;
  return (file);
}
