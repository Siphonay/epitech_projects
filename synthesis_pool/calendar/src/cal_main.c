/*
** cal_main.c for calendar in /home/sam/Rendu/Piscine_S/calendar
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Jul  1 16:46:54 2016 Alexis Viguié
** Last update Fri Jul  1 16:56:43 2016 Alexis Viguié
*/

#include <stdio.h>
#include <string.h>
#include "calendar.h"

int	main(int __attribute__((unused)) ac, char **av)
{
  char	buffer[READ_SIZE];
  int	ret_val;

  if (av[1] && !strcmp(HELP_OPTION, av[1]))
    {
      printf(CALENDAR_USAGE);
      return (CALENDAR_EXIT_SUCCESS);
    }
  while (scanf("%s", buffer) && (ret_val = calendar_use_stdin(buffer)));
  return (ret_val);
}
