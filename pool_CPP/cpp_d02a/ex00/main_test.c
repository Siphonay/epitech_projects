#include <stdio.h>
#include "simple_list.h"

int		main(void)
{
  t_list	list_head = NULL;
  unsigned int	size;
  double	i = 5.2;
  double	j = 42.5;
  double	k = 3.3;

  list_add_elem_at_back(&list_head, i);
  list_add_elem_at_back(&list_head, j);
  list_add_elem_at_back(&list_head, k);

  size = list_get_size(list_head);
  printf("There are %u elements on the list\n", size);
  list_dump(list_head);

  list_del_elem_at_back(&list_head);

  size =list_get_size(list_head);
  printf("There are %u elements on the list\n", size);
  list_dump(list_head);

  return (0);
}
