#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char  **av, char **ep)
{
  pid_t	pid;
  int	status;

  if (ac < 2)
    return (1);
  if ((pid = fork()) == 0)
    {
      execve("/bin/ruby", av, ep);
      exit(1);
    }
  else if (pid == -1)
    exit(1);
  else
    {
      if (wait(&status) == -1)
	exit(1);
      printf("hey!\n");
    }
  return (0);
}
