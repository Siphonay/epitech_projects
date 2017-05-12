/*
** setenv.c for setenv in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 12:27:20 2016 thibault derbre
** Last update Mon Apr 11 11:41:09 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	add_env_var(t_data *data, int y)
{
  int	col;
  int	len;
  char	**table;

  col = my_strlen(data->args[1]) + 2;
  if (data->args[2] != NULL)
    col += my_strlen(data->args[2]);
  if (data->max_col_env < col)
    data->max_col_env = col;
  table = create_char_table(y + 3, data->max_col_env);
  len = 0;
  col = 0;
  while (data->env[len] != NULL)
    {
      while (data->env[len][col] != '\0')
	{
	  table[len][col] = data->env[len][col];
	  col++;
	}
      table[len][col] = '\0';
      col = 0;
      len++;
    }
  free_char_table(data->env);
  data->env = add_the_var(table, len, data);
}

void	my_set_env(t_data *data)
{
  int	y;

  y = 0;
  if (data->args[1] == NULL)
    {
      my_env(data);
      return ;
    }
  while (data->env[y] != NULL)
    {
      if ((my_strcmp_setenv(data->args[1], data->env[y])) == 1)
	{
	  if (data->args[2] == NULL)
	    delete_value(data, y);
	  else
	    change_value(data, y);
	  return ;
	}
      y++;
    }
  add_env_var(data, y);
}
