/*
** client_exit.c for minitalk client in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Wed Feb 17 17:30:50 2016 Alexis Viguié
** Last update Wed Feb 17 17:31:27 2016 Alexis Viguié
*/

#include <stdlib.h>

void	client_fail_free_and_exit(char *str_tofree)
{
  free(str_tofree);
  exit(1);
}
