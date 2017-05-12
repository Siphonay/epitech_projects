/*
** main.c for main in /home/ruffet_m/rendu/CPE/CPE_2015_corewar/my_asm
**
** Made by mathieu ruffet
** Login   <ruffet_m@epitech.net>
**
** Started on  Fri Feb 26 09:41:38 2016 mathieu ruffet
** Last update Tue Mar 29 08:37:18 2016 Victor Herlin
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "asm.h"

int	main(int ac, char **av)
{
  int	fd;
  char	**tab;

  if (ac < 2)
    return (1);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (2);
  if ((tab = file_getbuf_in_tab(fd)) == NULL)
    return (3);
  free(tab);
  return (0);
}
