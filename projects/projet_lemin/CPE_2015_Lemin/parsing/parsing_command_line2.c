/*
** parsing_command_line.c for parsing the line in /home/ruffetm/rendu/CPE/CPE_2015_Lemin/parsing
**
** Made by Mathieu RUFFET
** Login   <ruffetm@epitech.net>
**
** Started on  Tue Apr 19 10:50:18 2016 Mathieu RUFFET
** Last update Wed Apr 20 16:45:12 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_lemin.h"

char	**lemin_getline_tab()
{
  char	buffer[2048];
  char	**save_buf;
  int	read_num;
  int	line;

  line = 1;
  read_num = 0;
  if ((save_buf = malloc(sizeof(char) * 2048)) == NULL)
    return (NULL);
  while (1)
    {
      if ((save_buf[line] = malloc(sizeof(char) * 2048)) == NULL)
	return (NULL);
      if (((read_num = read(FD_STDIN, buffer, 2048)) <= 0) || !read_num)
	return (save_buf);
      buffer[read_num] = '\0';
      save_buf[line] = buffer;
      line++;
  }
}
