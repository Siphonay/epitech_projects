/*
** get_next_line.c for gnl in /home/herlin_a/rendu/CPE/CPE_2015_Allum1
**
** Made by Victor Herlin
** Login   <herlin_a@epitech.net>
**
** Started on  Sun Feb 21 17:45:05 2016 Victor Herlin
** Last update Fri Mar 25 16:16:00 2016 Victor Herlin
*/

#include "asm.h"

char	*my_strcpy(char *s2, char *s1, int i)
{
  int	j;

  j = 0;
  while (s1[i])
    {
      s2[j] = s1[i];
      i++;
      j++;
    }
  s2[j] = 0;
  return (s2);
}

int	check_end_of_line(char *recup, char *line, char *buff)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(recup);
  while (line[j])
    {
      if (line[j] == '\n')
	{
	  recup[i] = 0;
	  j++;
	  buff = my_strcpy(buff, line, j);
	  return (1);
	}
      recup[i] = line[j];
      i++;
      j++;
    }
  buff[0] = 0;
  recup[i] = 0;
  return (0);
}

int	check_buffer(char *recup, char *buff)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(recup);
  while (buff[j])
    {
      if (buff[j] == '\n')
	{
	  recup[i] = 0;
	  j++;
	  buff = my_strcpy(buff, buff, j);
	  return (1);
	}
      recup[i] = buff[j];
      i++;
      j++;
    }
  buff[0] = 0;
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	buff[1000];
  char		*line;
  char		*recup;
  int		len_read;

  if ((line = malloc(sizeof(char) * 100001)) == NULL)
    return (NULL);
  if ((recup = malloc(sizeof(char) * 100000)) == NULL)
    return (NULL);
  recup[0] = '\0';
  if (check_buffer(recup, buff) == 1)
    return (recup);
  while ((len_read = read(fd, line, READ_SIZE)) > 0)
    {
      line[len_read] = '\0';
      if (check_end_of_line(recup, line, buff) == 1)
	return (recup);
    }
  if (recup != NULL)
    {
      if (recup[0] != 0)
	return (recup);
    }
  return (NULL);
}
