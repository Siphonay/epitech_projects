/*
** disp_tree.c for tree in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Apr 26 15:29:09 2016 Alexis Viguié
** Last update Tue Apr 26 17:57:50 2016 Simon Pedrono
*/

#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "tree.h"

void	put_symbol(int depth, char *name, bool last)
{
  int	counter;

  counter = 0;
  while (counter < depth)
    {
      if (!last)
	my_putstr("|");
      else
	my_putstr("`");
      if (counter == depth - 1)
	my_putstr("-- ");
      else
	my_putstr("   ");
	  counter++;
    }
  my_putstr(name);
  my_putstr("\n");
}

DIR		*is_correctdir(char *dir_name, int depth, t_options options)
{
  DIR	*dir_ptr;

  if (!(depth < options.level))
    return (NULL);
  if (!(dir_ptr = opendir(dir_name)))
    {
      my_putstr(dir_name);
      my_putstr(" [error opening dir]\n");
      return (NULL);
    }
  return (dir_ptr);
}

t_num		disp_dir(char *dir_name, int depth,
			 t_options options, t_num elems)
{
  DIR		*dir_ptr;
  struct dirent	*dc;

  if (!(dir_ptr = is_correctdir(dir_name, depth, options)))
    return (elems);
  put_symbol(depth++, dir_name, false);
  while ((dc = readdir(dir_ptr)))
    {
      if ((dc->d_name[0] != '.' && !options.all))
	{
	  if ((dc->d_type == DT_DIR) && (!(my_strcmp("..", dc->d_name))) &&
	      !(my_strcmp(".", dc->d_name)))
	    {
	      elems = disp_dir(dc->d_name, depth, options, elems);
	      elems.dir_num++;
	    }
	  else if (!options.dirs_only)
	    {
	      put_symbol(depth, dc->d_name, false);
	      elems.file_num++;
	    }
	}
    }
  closedir(dir_ptr);
  return (elems);
}

void	print_elems(t_num elems, t_options options)
{
  my_putstr("\n");
  my_putnbr(elems.dir_num);
  my_putstr(" director");
  if (elems.dir_num == 1)
    my_putstr("y");
  else
    my_putstr("ies");
  if (!options.dirs_only)
    {
      my_putstr(", ");
      my_putnbr(elems.file_num);
      my_putstr(" file");
      if (elems.file_num != 1)
	my_putstr("s");
    }
  my_putstr("\n");
}

void		disp_tree(char **av, t_options options)
{
  unsigned int	counter;
  bool		dir_in_args;
  t_num		elems;

  counter = (elems.file_num = elems.dir_num = 0) + 1;
  dir_in_args = false;
  while (av[counter])
    {
      if ((av[counter][0] != '-') &&
	  !(counter && my_isnum(av[counter]) && my_findletterL(av[counter - 1])))
	{
	  elems = disp_dir(av[counter], 0, options, elems);
	  dir_in_args = true;
	}
      counter++;
    }
  if (!dir_in_args)
    elems = disp_dir(".", 0, options, elems);
  print_elems(elems, options);
}
