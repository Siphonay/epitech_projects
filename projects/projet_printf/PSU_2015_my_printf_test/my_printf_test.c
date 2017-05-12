#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int	main()
{
  char	*ptr;

  ptr = malloc(sizeof(char) * 8);
  my_printf("hey %p bye\n", ptr);
}
