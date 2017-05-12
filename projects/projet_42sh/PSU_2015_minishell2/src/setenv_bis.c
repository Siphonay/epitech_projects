/*
** setenv_bis.c for setenv_bis in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr 11 11:40:52 2016 thibault derbre
** Last update Mon Apr 11 17:51:16 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	delete_value(t_data *data, int y)
{
  int	i;

  i = 0;
  while (data->env[y][i] != '=')
    i++;
  i++;
  while (data->env[y][i] != '\0')
    {
      data->env[y][i] = '\0';
      i++;
    }
}

void	realloc_table(t_data *data, int col)
{
  int	y;
  char	**table;
  int	i;

  y = 0;
  i = 0;
  data->max_col_env = col;
  while (data->env[y] != NULL)
    y++;
  table = create_char_table(y + 2, col);
  y = 0;
  while (data->env[y] != NULL)
    {
      while (data->env[y][i] != '\0')
	{
	  table[y][i] = data->env[y][i];
	  i++;
	}
      table[y][i] = '\0';
      i = 0;
      y++;
    }
  table[y] = NULL;
  free_char_table(data->env);
  data->env = table;
}

void	change_value(t_data *data, int y)
{
  int	col;
  int	len;

  col = my_strlen(data->args[1]);
  col += my_strlen(data->args[2]) + 2;
  if (data->max_col_env < col)
    realloc_table(data, col);
  col = 0;
  len = 0;
  delete_value(data, y);
  while (data->env[y][col] != '=')
    col++;
  col++;
  while (data->args[2][len] != '\0')
    {
      data->env[y][col] = data->args[2][len];
      col++;
      len++;
    }
  data->env[y][col] = '\0';
}

char	**copy_arg_one(t_data *data, char **table, int *i, int y)
{
  while (data->args[1][*i] != '\0')
    {
      table[y][*i] = data->args[1][*i];
      (*i)++;
    }
  return (table);
}

char	**add_the_var(char **table, int y, t_data *data)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  table = copy_arg_one(data, table, &i, y);
  if (data->args[2] == NULL)
    {
      table[y][i] = '=';
      table[y][i + 1] = '\0';
      table[y + 1] = NULL;
      return (table);
    }
  table[y][i] = '=';
  i++;
  while (data->args[2][j] != '\0')
    {
      table[y][i] = data->args[2][j];
      i++;
      j++;
    }
  table[y][i] = '\0';
  table[y + 1] = NULL;
  return (table);
}
