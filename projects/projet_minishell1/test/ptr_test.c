#include <stdio.h>

void	inc_ptr(int *ptr)
{
  *ptr += 4;
}

int	main(void)
{
  int	var;
  int	*ptr;
  char	pei;
  int	lulz;

  var = 6;
  ptr = &var;
  printf("var before calling fnc: %i\n", *ptr);
  inc_ptr(ptr);
  printf("var after calling fnc: %i\n", *ptr);
  return (0);
}
