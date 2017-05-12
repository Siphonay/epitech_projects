/*
** main.c for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 19:20:40 2016 Alexis Viguié
** Last update Sat Jan  9 20:47:14 2016 Alexis Viguié
*/

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "unarchive.h"

int	main(int ac, char **av)
{
  FILE	*archive;

  if (ac != 2)
    exit_usage(av[0]);
  if ((archive = fopen(av[1], "r")) == NULL)
    exit_file_error(av[1]);
  extract_arc(archive);
  fclose(archive);
  return (0);
}
