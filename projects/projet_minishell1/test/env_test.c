#include <stdio.h>

int		main(int __attribute__ ((unused)) ac,
		     char __attribute__ ((unused)) **av,
		     char **ep)
{
  static char	*newenv = "bonjour";
  unsigned int	counter;

  printf("current ep:\n");
  for (counter = 0; ep[counter]; counter++)
    printf("%s\n", ep[counter]);
  ep[4] = newenv;
  printf("\nchanged ep:\n");
  for (counter = 0; ep[counter]; counter++)
    printf("%s\n", ep[counter]);
  return (0);
}
