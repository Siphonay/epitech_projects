/*
** read_next_x_bytes.c for read next x bytes in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jan  7 10:04:28 2016 Alexis Viguié
** Last update Thu Jan  7 10:10:09 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>

char	*read_next_x_bytes(int fd, int x)
{
  char	*ret_buf;

  if ((ret_buf = malloc(sizeof(char) * x)) == NULL)
    return (ret_buf);
  if (read(fd, &ret_buf, x) < 1)
    {
      free(ret_buf);
      ret_buf = NULL;
    }
  return (ret_buf);
}
