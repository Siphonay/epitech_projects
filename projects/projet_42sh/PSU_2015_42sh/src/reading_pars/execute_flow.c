/*
** execute_flow.c for execute_flow in /home/zaza/rendu/PSU_2015_42sh/src/reading_pars/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sun Jun  5 22:20:30 2016 thibault derbre
** Last update Sun Jun  5 22:36:40 2016 thibault derbre
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "get_next_line.h"

char		**take_cmd(char **cmd, char *str, int fd)
{
  char		*s;
  int		len;

  my_putstr("? ");
  while ((s = get_next_line(STDIN_FILENO)) != NULL)
    {
      if ((strcmp(s, str)) == 0)
	break;
      len = strlen(s);
      write(fd, s, len);
      write(fd, "\n", 1);
      free(s);
      my_putstr("? ");
    }
  return (cmd);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*str;

  i = strlen(src);
  j = strlen(dest);
  if ((str = malloc((i + j) + 1 * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (src[i] != '\0')
    {
      str[j] = src[i];
      i++;
      j++;
    }
  i = 0;
  while (dest[i] != '\0')
    {
      str[j] = dest[i];
      i++;
      j++;
    }
  str[j] = '\0';
  return (str);
}

int		check_left(t_elem *elem, int *y, int fd[2], char **cmd)
{
  char	*str;

  if ((check_flow(elem->cmd[*y])) == 3)
    {
      fd[0] = open(elem->cmd[*y + 1], O_RDONLY);
      (*y)++;
    }
  if ((check_flow(elem->cmd[*y])) == 4)
    {
      if ((str = my_strcat(elem->cmd[*y + 1], "/tmp/42.")) == NULL)
	return (-1);
      if ((fd[0] = open(str, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
	exit(1);
      if ((take_cmd(cmd, elem->cmd[*y + 1], fd[0])) == NULL)
	exit(1);
      close(fd[0]);
      fd[0] = open(str, O_RDONLY);
      (*y)++;
    }
  return (0);
}

int		check_right(t_elem *elem, int *y, int fd[2])
{
  if ((check_flow(elem->cmd[*y])) == 1)
    {
      fd[1] = open(elem->cmd[*y + 1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR
		   | S_IRGRP | S_IWGRP | S_IWUSR);
      (*y)++;
    }
  if ((check_flow(elem->cmd[*y])) == 2)
    {
      fd[1] = open(elem->cmd[*y + 1], O_WRONLY | O_CREAT | O_APPEND, S_IRUSR
		   | S_IRGRP | S_IWGRP | S_IWUSR);
      (*y)++;
    }
  return (0);
}

void		execute_with_flow(t_elem *elem, char **cmd, t_data *data, int f)
{
  int		y;
  int		fd[2];

  y = 0;
  fd[0] = -2;
  fd[1] = -2;
  while (elem->cmd[y] != NULL)
    {
      check_right(elem, &y, fd);
      check_left(elem, &y, fd, cmd);
      y++;
    }
  if (f == 0)
    my_exec(data->env, cmd, data, fd);
  else
    exec_pipe(data->env, cmd, data, fd);
}
