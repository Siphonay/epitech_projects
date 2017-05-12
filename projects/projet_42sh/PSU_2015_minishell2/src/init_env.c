/*
** init_env.c for init_env in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 19:21:37 2016 thibault derbre
** Last update Mon Apr 11 11:02:38 2016 thibault derbre
*/

#include "get_next_line.h"
#include "mysh.h"

void	take_var_env(char **env, int *lines, int *col)
{
  int	y;
  int	len;

  y = 0;
  *col = 0;
  if (env[0] == NULL)
    exit(1);
  while (env[y] != NULL)
    {
      if ((len = my_strlen(env[y])) > *col)
	*col = len;
      y++;
    }
  *lines = y;
}

t_data	*copy_var_env(t_data *data, char **env)
{
  int	y;
  int	i;

  y = 0;
  i = 0;
  while (env[y] != NULL)
    {
      while (env[y][i] != '\0')
	{
	  data->env[y][i] = env[y][i];
	  i++;
	}
      data->env[y][i] = '\0';
      i = 0;
      y++;
    }
  data->env[y] = NULL;
  return (data);
}

t_data	*copy_env(t_data *data, char **env)
{
  int	col;
  int	lines;

  take_var_env(env, &lines, &col);
  data->max_col_env = col + 1;
  data->env = create_char_table(lines + 1, col + 1);
  data = copy_var_env(data, env);
  return (data);
}
