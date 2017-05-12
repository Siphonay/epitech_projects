#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(int ac, char **av)
{
  int	fd;
  char	*gnl;

  if (ac != 2)
    return (1);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  while ((gnl = get_next_line(fd)) != NULL)
    {
      printf("%s\n", gnl);
      free(gnl);
    }
  return (0);
}
