/*
** show_messages.c for show_mesages in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 14:43:25 2016 thibault derbre
** Last update Sat Apr  9 14:45:11 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

void	show_error(t_data *data)
{
  my_putstr(data->command);
  my_putstr(": Command not found.\n");
}
