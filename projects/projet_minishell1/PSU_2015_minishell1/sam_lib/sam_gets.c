/*
** sam_gets.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 18 13:55:32 2016 Alexis Viguié
** Last update Tue Jan 19 11:48:53 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "sam.h"
#include "sam_gets.h"

char	*get_initial_return_str(int fd)
{
  char	*ret_init_str;

  if (!(ret_init_str = malloc(sizeof(char) * (READ_SIZE + 1))) ||
      read(fd, ret_init_str, READ_SIZE) < 1)
    return (NULL);
  ret_init_str[READ_SIZE] = '\0';
  return (ret_init_str);
}

unsigned int	check_endpos(char *param_str)
{
  unsigned int	counter;

  counter = 0;
  while (param_str[counter] && param_str[counter] != '\n')
    counter++;
  if (param_str[counter] == '\n')
    return (counter);
  else
    return (0);
}

char	*get_full_return_str(char *init_str,  int fd)
{
  char	*add_str;
  char	*tmp_str;

  while (!check_endpos(init_str))
    {
      if (!(add_str = (get_add_str(init_str, fd))))
	return (NULL);
      if (!(tmp_str = get_tmp_str(init_str)))
	{
	  free(add_str);
	  return (NULL);
	}
      free(init_str);
      if (!(init_str = get_cat_str(tmp_str, add_str)))
	return (NULL);
      free(tmp_str);
      free(add_str);
    }
  return (init_str);
}

char		*sam_gets(int fd)
{
  char		*full_gets;
  char		*ret_gets;

  if (!(full_gets = get_initial_return_str(fd)))
    return (NULL);
  if (!(full_gets = get_full_return_str(full_gets, fd)))
    return (NULL);
  if (!(ret_gets = sam_strncpy(full_gets, check_endpos(full_gets))))
    {
      free(full_gets);
      return (NULL);
    }
  free(full_gets);
  return (ret_gets);
}
