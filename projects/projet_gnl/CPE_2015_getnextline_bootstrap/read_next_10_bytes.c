/*
** read_next_10_bytes.c for read next 10 bytes in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jan  7 09:49:30 2016 Alexis Viguié
** Last update Thu Jan  7 10:09:49 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>

char	*read_next_10_bytes(int fd)
{
  char	*ret_buf;

  if ((ret_buf = malloc(sizeof(char) * 10)) == NULL)
    return (ret_buf);
  if (read(fd, ret_buf, 10) < 1)
    {
      free(ret_buf);
      ret_buf = NULL;
    }
  return (ret_buf);
}
