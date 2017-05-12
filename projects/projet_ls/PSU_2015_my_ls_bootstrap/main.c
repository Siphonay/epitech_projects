/*
** main.c for ls bootstrap in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Nov 16 10:34:27 2015 Alexis Viguié
** Last update Mon Nov 16 14:26:14 2015 Alexis Viguié
*/

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

int	main(int ac, char **av)
{
  DIR	*dirf;
  struct dirent	*filename;

  if (ac != 2)
    {
      my_putstr_err(av[0]);
      my_putstr_err(": filename");
      return (1);
    }
  dirf = opendir(av[1]);
  filename = readdir(dirf);
  my_putstr("Name: ");
  my_putstr(filename[0].d_name);
  my_putstr("\nType: ");
  write(1, &filename[0].d_type, 1);
  my_putstr("\nInode: ");
  my_put_nbr(filename[0].d_ino);
  my_putstr("\nHard Link: ");

}
