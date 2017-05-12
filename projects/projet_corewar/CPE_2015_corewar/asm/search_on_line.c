/*
** search_on_line.c for searching char or label in /home/merlin/rendu/CPE/CPE_2015_corewar
**
** Made by Victor Herlin
** Login   <merlin@epitech.net>
**
** Started on  Tue Mar 29 08:47:26 2016 Victor Herlin
** Last update Tue Mar 29 09:27:21 2016 Victor Herlin
*/

#include "asm.h"

int	search_label_char_on_line(char *line)
{
  int	i;

  i = 0;
  while (line[i])
    {
      if (line[i] == LABEL_CHAR && \
	  (line[i + 1] == ' ' || line[i + 1] == '\0'))
	{
	  if (i == 0)
	    return (2);
	  return (1);
	}
      i++;
    }
  return (0);
}

char	*search_label_name(char *line)
{
  char	*name;
  int	i;

  if ((name = malloc(sizeof(char) * my_strlen(line))) == NULL)
    return (NULL);
  i = 0;
  while (i != LABEL_CHAR && line[i] != '\0')
    {
      name[i] = line[i];
      i++;
    }
  return (name);
}
