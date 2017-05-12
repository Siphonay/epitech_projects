/*
** alloca_test.c for alloca test in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan  6 16:44:43 2016 Alexis Viguié
** Last update Wed Jan  6 16:44:45 2016 Alexis Viguié
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <alloca.h>

void	atest_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

void	exit_error(char *error_message)
{
  atest_putstr(error_message);
  exit(1);
}

int		main(int ac, char **av)
{
  struct stat	filestat;
  char		*filecontents;
  int		atest_fd;

  if (ac != 2)
    exit_error("this program requires one filename as argument\n");
  if ((atest_fd = open(av[1], O_RDONLY)) == -1)
    exit_error("file opening error\n");
  if ((stat(av[1], &filestat)) == -1)
    exit_error("stat error\n");
  if ((filecontents = alloca(sizeof(char) * filestat.st_size)) == NULL)
    exit_error("alloca error\n");
  read(atest_fd, filecontents, filestat.st_size);
  atest_putstr(filecontents);
  return (0);
}
