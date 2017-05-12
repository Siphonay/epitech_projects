/*
** unsetenv.c for unsetenv in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 12:27:27 2016 thibault derbre
** Last update Mon Apr 11 18:08:23 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	unset_var(t_data *data, int y, int size)
{
  char	**table;
  int	line;
  int	col;
  int	j;

  col = 0;
  line = 0;
  j = 0;
  table = create_char_table(size + 1, data->max_col_env);
  while (data->env[j] != NULL)
    {
      while (data->env[j][col] != '\0')
	{
	  table[line][col] = data->env[j][col];
	  col++;
	}
      table[line][col] = '\0';
      col = 0;
      line++;
      j++;
      (j == y ? j = j + 1 : 0);
    }
  table[line] = NULL;
  free_char_table(data->env);
  data->env = table;
}

void	my_unsetenv(t_data *data)
{
  int	y;
  int	size;

  y = 0;
  size = 0;
  if (data->args[1] == NULL)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      return ;
    }
  while (data->env[y] != NULL)
    {
      if ((my_strcmp_setenv(data->args[1], data->env[y])) == 1)
	{
	  while (data->env[size] != NULL)
	    size++;
	  unset_var(data, y, size);
	  return ;
	}
      y++;
    }
}
