/*
** my_echo.c for PSU_2015_42sh
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Sun Jun 05 11:41:40 2016 pedron_s
** Last update	Sun Jun 05 11:42:55 2016 pedron_s
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mysh.h"

int	my_pars(char **cmd)
{
  int	y;
  int	x;
  int	sc;
  int	dc;

  sc = 0;
  dc = 0;
  y = 0;
  while (cmd[y])
    {
      x = 0;
      while (cmd[y][x] != '\0')
	{
	  cmd[y][x] == '\'' ? sc++ : 0;
	  cmd[y][x] == '\"' ? dc++ : 0;
	  x++;
	}
      y++;
    }
  if (sc % 2 != 0)
    return (1);
  if (dc % 2 != 0)
    return (2);
  return (0);
}

int	my_parspar(char **cmd)
{
  int	y;
  int	x;
  int	po;
  int	pf;

  po = pf = 0;
  y = 0;
  while (cmd[y])
    {
      x = 0;
      while (cmd[y][x] != '\0')
	{
	  cmd[y][x] == '(' ? po++ : 0;
	  cmd[y][x] == ')' ? pf++ : 0;
	  x++;
	}
      y++;
    }
  if (po != 0 && pf != 0)
    return (5);
  if (po % 2 != 0)
    return (3);
  if (pf % 2 != 0)
    return (4);
  return (0);
}

void	my_error(int i)
{
  if (i == 1)
    printf("Unmatched \'.\n");
  else if (i == 2)
    printf("Unmatched \".\n");
  if (i == 3)
    printf("Too many ('s.\n");
  if (i == 4)
    printf("Too many )'s.\n");
  if (i == 5)
    printf("Badly placed ()'s.\n");
}

void	my_dis(char **cmd, int	pre)
{
  int	y;
  int	x;

  y = 2;
  if (pre)
    y = 1;
  while (cmd[y])
    {
      x = 0;
      while (cmd[y][x] != '\0')
	{
	  if (cmd[y][x] != '"' && cmd[y][x] != '\'')
	    my_putchar(cmd[y][x]);
	  x++;
	}
      y++;
      if (cmd[y])
	my_putchar(' ');
    }
  if (pre)
    printf("\n");
}

int	echo(char **cmd, char **env)
{
      (void)env;
      int	i;
  int	pre;

  i = 0;
  pre = 1;
  if (cmd[1] != NULL)
  if ((strcmp("-n", cmd[1])) == 0)
    pre = 0;
  if ((i = my_pars(cmd)) != 0)
    {
      my_error(i);
      return (-1);
    }
  if ((i = my_parspar(cmd)) != 0)
    {
      my_error(i);
      return (-1);
    }
  my_dis(cmd, pre);
  return (0);
}
