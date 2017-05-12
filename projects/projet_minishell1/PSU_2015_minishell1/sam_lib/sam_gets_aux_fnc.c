/*
** sam_gets_aux_fnc.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 18 15:15:57 2016 Alexis Viguié
** Last update Mon Jan 18 16:43:06 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "sam.h"

char	*get_add_str(char *init_str, int fd)
{
  char	*str_ret;

  if (!(str_ret = malloc(sizeof(char) * (READ_SIZE + 1))) ||
      read(fd, str_ret, READ_SIZE) < 1)
    {
      free(init_str);
      return (NULL);
    }
  str_ret[READ_SIZE] = '\0';
  return (str_ret);
}

char	*get_tmp_str(char *init_str)
{
  char	*str_ret;

  if (!(str_ret = sam_strncpy(init_str, sam_strlen(init_str))))
    {
      free(init_str);
      return (NULL);
    }
  return (str_ret);
}

char	*get_cat_str(char *tmp_str, char *add_str)
{
  char	*str_ret;

  if (!(str_ret = sam_strncat(tmp_str, add_str, sam_strlen(add_str))))
    {
      free(tmp_str);
      free(add_str);
      return (NULL);
    }
  return (str_ret);
}
