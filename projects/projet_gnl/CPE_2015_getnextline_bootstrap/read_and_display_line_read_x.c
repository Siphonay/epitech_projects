/*
** read_and_display_line_read_x.c for read and display line read x in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jan  7 10:38:36 2016 Alexis Viguié
** Last update Thu Jan  7 10:54:14 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>

void	read_and_display_line_read_x(int fd, int x)
{
  char	*cur_buf;
  int	counter;
  int	isnl;

  if ((cur_buf = malloc(sizeof(char) * x)) != NULL)
    {
      isnl = 0;
      while (read(fd, cur_buf, x) > 0 && !isnl)
	{
	  counter = 0;
	  while (cur_buf[counter] && cur_buf[counter] != '\n')
	    {
	      write(1, &cur_buf[counter], 1);
	      counter++;
	    }
	  isnl = (!cur_buf[counter] && counter < x) || cur_buf[counter] == '\n';
	}
    }
  free(cur_buf);
}
