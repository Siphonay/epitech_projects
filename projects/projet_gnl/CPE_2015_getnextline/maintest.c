#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(int ac, char **av)
{
  char	*s;

  while ((s = get_next_line(0)))
  {
    printf("%s\n", s);
    free(s);
  }
  return (0);
}
