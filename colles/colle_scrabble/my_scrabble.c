/*
** my_scrabble.c for my scrabble in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov 26 16:27:38 2015 Alexis Viguié
** Last update Thu Nov 26 17:48:28 2015 Alexis Viguié
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "scrabble.h"

int	main(int ac, char **av)
{
  int	scrabble_fd;

  if (ac != 2)
    {
      my_putstr_err("usage: my_scrabble file");
      return (1);
    }
  if ((scrabble_fd = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr_err("error: file not found");
    }
  if (scrabble_eval(scrabble_fd))
    {
      return (1);
      close(scrabble_fd);
    }
  close(scrabble_fd);
  return (0);
}
