/*
** main.c for my poker in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Dec 10 14:02:54 2015 Alexis Viguié
** Last update Thu Dec 10 15:43:53 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "poker.h"

t_list		*set_initial_list(char **players_list)
{
  t_list	*players;
  int		counter;

  counter = 0;
  while (players_list[counter])
    {
      if (counter)
	list_push_back(&players, players_list[counter]);
      else
	list_push_front(&players, players_list[counter]);
      counter++;
    }
  return (players);
}

char		*get_operation()
{
  char		stdin_buff[2048];
  char		*operation_ret;
  int		counter;
  int		counter2;

  read(0, stdin_buff, 2048);
  counter = 0;
  while (stdin_buff[counter] != '\n')
    counter++;
  if ((operation_ret = malloc(sizeof(char) * (counter + 1))) == NULL)
    {
      my_putstr_err("MALLOC ERROR!!!\n");
      exit(1);
    }
  operation_ret[counter] = '\0';
  counter2 = 0;
  while (counter2 < counter)
    {
      operation_ret[counter2] = stdin_buff[counter2];
      counter2++;
    }
  return (operation_ret);
}

int		main(int ac, char **av)
{
  t_list	*players;
  char		*operation;

  if (ac < 2)
    {
      my_putstr_err("usage: ");
      my_putstr_err(av[0]);
      my_putstr_err(" player1 [player2 ...]\n");
      return (1);
    }
  players = set_initial_list(av);
  operation = get_operation();
  while (my_strcmp(operation, "quit"))
    {
      process_operation(players, operation);
      operation = get_operation();
    }
  free(operation);
  free(players);
  return (0);
}
