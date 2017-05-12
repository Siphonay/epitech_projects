/*
** load.c for 42 in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/conf_file/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Tue May 31 19:37:58 2016 Nolann Méléard
** Last update Sun Jun  5 14:50:31 2016 Nolann Méléard
*/

#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mysh.h"
#include "get_next_line.h"

char	**load_file()
{
  char	**file;
  char	*str;
  int	fd;
  int	i;

  fd = 0;
  if ((fd = open("./.conf", O_RDONLY)) == -1)
    return (NULL);
  file = NULL;
  i = 0;
  while ((str = get_next_line(fd)) != NULL)
    i++;
  if ((close(fd)) == 1)
    return (NULL);
  if ((fd = open("./.conf", O_RDONLY)) == -1)
    return (NULL);
  file = doublearray(i, PATH_MAX);
  i = 0;
  while ((str = get_next_line(fd)) != NULL)
    {
      file[i] = strcpy(file[i], str);
      i++;
    }
  file[i] = NULL;
  return (file);
}

t_data		*get_file(t_data *data)
{
  char		**file;

  data->file = first_init_file();
  file = load_file();
  if (file == NULL)
    return (data);
  if (load_alias(file, data) == -1)
    return (data);
  if (export(file, data) == -1)
    return (data);
  return (data);
}
