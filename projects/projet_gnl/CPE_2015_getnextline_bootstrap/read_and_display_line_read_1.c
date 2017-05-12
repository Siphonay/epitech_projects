/*
** read_and_display_line_read_1.c for read and display line read 1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jan  7 10:12:59 2016 Alexis Viguié
** Last update Thu Jan  7 10:33:36 2016 Alexis Viguié
*/

#include <unistd.h>

void	read_and_display_line_read_1(int fd)
{
  char	read_char;

  while (read(fd, &read_char, 1) > 0 && read_char != '\n' && read_char != '\0')
    write(1, &read_char, 1);
}
