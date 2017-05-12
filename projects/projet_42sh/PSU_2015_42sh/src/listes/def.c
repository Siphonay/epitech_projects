/*
** def.c for PSU_2015_42sh
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Fri May 27 11:11:22 2016 pedron_s
** Last update	Tue May 31 18:55:43 2016 pedron_s
*/

#include <unistd.h>
#include <stdlib.h>
#include "liste.h"

char	*malloc_def(char *def)
{
  def = NULL;
  if ((def = malloc(sizeof(char) * 11)) == NULL)
    return (NULL);
  def[0] = ' ';
  def[1] = '|';
  def[2] = ';';
  def[3] = '&';
  def[4] = '\0';
  return (def);
}
