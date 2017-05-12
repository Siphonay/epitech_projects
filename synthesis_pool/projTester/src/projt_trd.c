/*
** projt_trd.c for projTester in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jun 23 15:19:40 2016 Alexis Viguié
** Last update Sat Jun 25 10:48:41 2016 Alexis Viguié
*/

#include <unistd.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "projt.h"

void	print_name(int level, const char *name, bool isadir)
{
  int	counter;

  counter = 0;
  while (counter < level)
    {
      fputs(TRD_STR_DEPTH, stdout);
      counter++;
    }
  fputs(name, stdout);
  if (isadir)
    fputc('/', stdout);
  fputc('\n', stdout);
}

void	print_dir(struct dirent *entry, int level, const char *name)
{
  char	path[PATH_MAX];
  int	path_len;

  if (entry->d_type == DT_DIR)
    {
      path_len = snprintf(path, PATH_MAX - 1,
			  "%s/%s", name, entry->d_name);
      path[path_len] = '\0';
      if (!(!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")))
	{
	  print_name(level, entry->d_name, true);
	  projt_trd(path, level + 1);
	}
    }
  else
    print_name(level, entry->d_name, false);
}

int		projt_trd(const char *name, int level)
{
  DIR		*dir;
  struct dirent	*entry;

  if (!level)
    print_name(level++, name, true);
  if (!(dir = opendir(name)) || !(entry = readdir(dir)))
    return (PROJT_EXIT_FAILURE);
  print_dir(entry, level, name);
  while ((entry = readdir(dir)))
    print_dir(entry, level, name);
  closedir(dir);
  return (PROJT_EXIT_SUCCESS);
}
