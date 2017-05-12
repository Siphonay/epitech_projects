/*
** main.c for main in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 17:34:02 2016 thibault derbre
** Last update Mon Apr 11 19:36:29 2016 thibault derbre
*/

#include "get_next_line.h"
#include "mysh.h"

int	main(int argc, char **argv, char **env)
{
  t_data *data;
  int	i;

  (void)argv;
  (void)argc;
  if ((data = malloc(sizeof(t_data))) == NULL)
    return (-1);
  data = copy_env(data, env);
  data = my_sh(data);
  if (data->if_exit == 1)
    {
      i = data->exit_id;
      free(data);
      return (i);
    }
  free(data);
  return (0);
}
