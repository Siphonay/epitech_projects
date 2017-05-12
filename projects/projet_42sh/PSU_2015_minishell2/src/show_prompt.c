/*
** show_prompt.c for prompt in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 20:03:23 2016 thibault derbre
** Last update Tue Apr  5 14:07:26 2016 thibault derbre
*/

#include <stdlib.h>
#include "mysh.h"
#include "get_next_line.h"

void	show_prompt(t_data *data)
{
  data->nb_cmd++;
  my_putstr("> ");
}
