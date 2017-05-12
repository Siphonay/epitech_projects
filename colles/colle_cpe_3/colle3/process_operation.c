/*
** process_operation.c for my poker in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Dec 10 14:39:10 2015 Alexis Viguié
** Last update Thu Dec 10 15:59:01 2015 Alexis Viguié
*/

#include <stdlib.h>
#include "poker.h"

void		player_operations(t_list *players, char *op)
{
  int		counter;
  int		counter2;
  char		*player_name;

  counter = 4;
  while (op[counter])
    counter++;
  if ((player_name = malloc(sizeof(char) * (counter - 4 + 1))) == NULL)
    {
      my_putstr_err("MALLOC ERROR!!!\n");
      exit(1);
    }
  player_name[counter - 4] = '\0';
  counter2 = 4;
  while (counter2 - counter)
    {
      player_name[counter2 - 4] = op[counter2 - 4];
      counter2++;
    }
  if (op[0] == 'a')
    list_push_back(&players, player_name);
  else
    delete_list(&players, player_name);
  free(player_name);
  aff_list(&players);
}

void		process_operation(t_list *players, char *op)
{
  if (my_strcmp(op, "quit") != 0)
    {
      if ((op[0] == 'a' &&  op[1] == 'd' && op[2] == 'd') ||
	   (op[0] == 'd' &&  op[1] == 'e' && op[2] == 'l'))
	{
	  if (op[3] != ' ' && !(op[4]))
	    my_putstr_err("please, input a player name\n");
	  else
	    {
	      player_operations(players, op);
	    }
	}
      else if ((my_strcmp(op, "play") != 0) || (my_strcmp(op, "print") != 0))
	{
	  if (my_strcmp(op,"play") != 0)
	    turn_dealer(&players);
	  aff_list(&players);
	}
      else
	my_putstr_err("plese, input a valid command\n");
    }
}
