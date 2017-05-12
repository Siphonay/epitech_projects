/*
** detect_bitmap.c for bitmap detect in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan  6 17:35:36 2016 Alexis Viguié
** Last update Wed Jan  6 19:24:26 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void	db_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

int	exit_error(char *err_message)
{
  db_putstr(err_message);
  exit(1);
}

int	main(int ac, char **av)
{
  int	db_fd;
  char	ftype[2];

  if (ac != 2)
    exit_error("use a filename in argument\n");
  if ((db_fd = open(av[1], O_RDONLY)) == -1)
    exit_error("open error\n");
  read(db_fd, ftype, 2);
  if ((ftype[0] == 'B') && (ftype[1] == 'M'))
    db_putstr("this is a bitmap file.\n");
  else
    db_putstr("this is not a bitmap file.\n");
  return (0);
}
