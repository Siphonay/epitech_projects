/*
** main.c for bsq in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Dec 14 17:16:02 2015 Alexis Viguié
** Last update Sun Dec 20 13:40:28 2015 Alexis Viguié
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

int		main(int ac, char **av)
{
  int		bsq_fd;
  struct stat	filestat;
  char		*filecontents;
  int		row_number;
  char		*plat;

  if (ac != 2)
    exit_args(av[0]);
  if ((bsq_fd = open(av[1], O_RDONLY)) == -1)
    exit_file_not_found(av[1]);
  stat(av[1], &filestat);
  if ((filecontents = malloc(sizeof(char) * filestat.st_size)) == NULL)
    exit_mllc();
  read(bsq_fd, filecontents, filestat.st_size);
  if ((row_number = get_row_number(filecontents)) == 0)
    exit_incorrect_file(filecontents);
  if ((plat = get_plat(filecontents, row_number)) == NULL)
    exit_incorrect_file(filecontents);
  free(filecontents);
  proc_plat(plat, row_number);
  free(plat);
  return (0);
}
