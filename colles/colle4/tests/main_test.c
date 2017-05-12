#include <stdlib.h>
#include "transformer.h"

int	main(int ac, char **av)
{
  char	*test;

  if (ac != 2)
    return (1);
  my_putstr(av[1]);
  my_putstr("\n");
  my_putstr((test = my_str_rotation(av[1])));
  my_putstr("\n");
  free(test);
  return (0);
}
