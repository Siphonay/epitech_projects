#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int	main(int ac, char **av)
{
  char	buf[256];
  DIR	*testdir;

  if (ac < 1)
    return (1);
  printf("current directory before change: %s\n", getcwd(buf, 256));
  if ((testdir = opendir(av[1])))
    {
      if (closedir(testdir))
	return (1);
      chdir(av[1]);
      printf("current directory after change: %s\n", getcwd(buf, 256));
      return (0);
    }
  else
    return (1);
}
