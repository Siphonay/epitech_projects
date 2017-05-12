/*
** check_tetromino.c for bstetris in /home/sam/Rendu/Projets/projet_tetris/PSU_2015_bstetris
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Mon Feb 22 16:39:55 2016 Alexis Viguié
** Last update Mon Feb 22 17:08:48 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void		bs_putstr(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

void	check_tetromino(char *tetrimino, char *filename)
{
  unsigned int	counter;

  bs_putstr("Tetriminos : Name ");
  counter = 0;
  while (filename[counter] != '.' && filename[counter])
    {
      write(1, &filename[counter], 1);
      counter++;
    }
  bs_putstr(" : Size ");
  counter = 0;
  write(1, &tetrimino[counter], 1);
  bs_putstr("*");
  counter += 2;
  write(1, &tetrimino[counter], 1);
  bs_putstr(" : Color ");
  counter += 2;
  write(1, &tetrimino[counter], 1);
  bs_putstr(" :");
  counter++;
  bs_putstr(&tetrimino[counter]);
}

int	main(int ac, char **av)
{
  int		fd;
  struct stat	file_stat;
  char		*buffer_file;

  if (ac != 2)
    return (1);
  if ((fd = open(av[1], O_RDONLY)) < 0)
    return (1);
  stat(av[1], &file_stat);
  if (!(buffer_file = malloc(sizeof(char) * file_stat.st_size)))
    return (1);
  read(fd, buffer_file, file_stat.st_size);
  check_tetromino(buffer_file, av[1]);
  free(buffer_file);
  return (0);
}
