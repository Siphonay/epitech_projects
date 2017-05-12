/*
** read_next_char.c for read next char in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jan  7 09:38:42 2016 Alexis Viguié
** Last update Thu Jan  7 09:46:49 2016 Alexis Viguié
*/

#include <unistd.h>

char	read_next_char(int fd)
{
  char	ret_char;

  if (read(fd, &ret_char, 1) != -1)
    return (ret_char);
  else
    return ('\0');
}
