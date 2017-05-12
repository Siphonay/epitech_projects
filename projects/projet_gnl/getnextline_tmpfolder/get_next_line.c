/*
** get_next_line.c for get next line in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Jan 15 17:22:31 2016 Alexis Viguié
** Last update Sat Jan 16 18:03:01 2016 Alexis Viguié
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		gnl_op(char *param_string, char operation)
{
  unsigned int	counter;

  if (operation == 'c')
    {
      counter = 0;
      while (param_string[counter] && param_string[counter] != '\n')
	counter++;
      if (param_string[counter] == '\n')
	{
	  return (counter);
	}
      else
	return (-1);
    }
  else if (operation == 'l')
    {
      counter = 0;
      while (param_string[counter])
	counter++;
      return (counter);
    }
  else
    return (-1);
}

char	*gnl_strcpy(char *param_string)
{
  char	*ret_string;
  int	counter;

  if ((ret_string =
       malloc(sizeof(char) * (gnl_op(param_string, 'l') + 1))) == NULL)
    return (NULL);
  ret_string[gnl_op(param_string, 'l')] = '\0';
  counter = 0;
  while (counter < gnl_op(param_string, 'l'))
    {
      ret_string[counter] = param_string[counter];
      counter++;
    }
  free(param_string);
  return (ret_string);
}

char		*truncate_endstring(char *param_string)
{
  unsigned int	counter;
  char		*ret_string;

  counter = 0;
  while (param_string[counter] && param_string[counter] != '\n')
    counter++;
  if ((ret_string = malloc(sizeof(char) * (counter + 1))) == NULL)
    {
      free(param_string);
      return (NULL);
    }
  ret_string[counter] = '\0';
  counter = 0;
  while (param_string[counter] && param_string[counter] != '\n')
    {
      ret_string[counter] = param_string[counter];
      counter++;
    }
  return (ret_string);
}

char	*gnl_strcat(char *dest, char *src)
{
  char		*ret_str;
  unsigned int	counter;

  if ((ret_str = malloc(sizeof(char) *
			(gnl_op(dest, 'l') + gnl_op(src, 'l') + 1))) == NULL)
    return (NULL);
  ret_str[gnl_op(dest, 'l') + gnl_op(src, 'l')] = '\0';
  counter = 0;
  while (dest[counter])
    {
      ret_str[counter] = dest[counter];
      counter++;
    }
  counter = 0;
  while (src[counter])
    {
      ret_str[counter + gnl_op(dest, 'l')] = src[counter];
      counter++;
    }
  free(dest);
  free(src);
  return (ret_str);
}

char			*get_next_line(int fd)
{
  static unsigned int	gnl_call_count = 0;
  static char		*lastread;
  char			*ret_gnl;
  char			*add_gnl;
  int			counter;

  if (gnl_call_count == 0)
    {
      if ((ret_gnl = malloc(sizeof(char) * READ_SIZE + 1)) == NULL ||
	read(fd, ret_gnl, READ_SIZE) < 1)
	return (NULL);
      ret_gnl[READ_SIZE] = '\0';
    }
  else
    ret_gnl = gnl_strcpy(lastread);
  while (gnl_op(ret_gnl, 'c') == -1)
    {
      if ((add_gnl = malloc(sizeof(char) * READ_SIZE + 1)) == NULL ||
	  read(fd, add_gnl, READ_SIZE) < 1)
	return (NULL);
      add_gnl[READ_SIZE] = '\0';
      ret_gnl = gnl_strcat(ret_gnl, add_gnl);
    }
  if ((lastread = malloc(sizeof(char) *
			 (gnl_op(ret_gnl, 'l') - gnl_op(ret_gnl, 'c'))))
      == NULL)
    return (NULL);
  lastread[gnl_op(ret_gnl, 'l') - gnl_op(ret_gnl, 'c') - 1] = '\0';
  counter = 0;
  while (counter + 1 < gnl_op(ret_gnl, 'l') - gnl_op(ret_gnl, 'c'))
    {
      lastread[counter] = ret_gnl[counter + 1 + gnl_op(ret_gnl, 'c')];
      counter++;
    }
  gnl_call_count++;
  return (truncate_endstring(ret_gnl));
}
