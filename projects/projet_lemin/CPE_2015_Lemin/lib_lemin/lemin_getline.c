/*
** parsing_command_line.c for parsing the line in /home/ruffetm/rendu/CPE/CPE_2015_Lemin/parsing
**
** Made by Mathieu RUFFET
** Login   <ruffetm@epitech.net>
**
** Started on  Tue Apr 19 10:50:18 2016 Mathieu RUFFET
** Last update Tue Apr 19 17:20:52 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_lemin.h"

char	*lemin_getline()
{
  char	buffer[2048];
  char	*save_buf;
  int	test;

  test = 0;
  if ((save_buf = malloc(sizeof(char) * 2048)) == NULL)
    return (NULL);
  while (1)
    {
      if (((test = read(FD_STDIN, buffer, 2048)) <= 0) || !test)
	return (NULL);
      buffer[test] = '\0';
      save_buf = buffer;
    }
  return (save_buf);
}
