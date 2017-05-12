/*
** client_main.c for minitalk client in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Feb  8 17:27:34 2016 Alexis Viguié
** Last update Wed Feb 17 17:29:32 2016 Alexis Viguié
*/

#include "mtk_client.h"
#include "sam.h"

int		main(int ac, char **av)
{
  unsigned int	counter;

  if (ac != 3)
    return (1);
  counter = 0;
  while (av[2][counter])
    {
      client_send_char(av[2][counter], sam_str_to_int(av[1]));
      counter++;
    }
  client_send_char('\n', sam_str_to_int(av[1]));
  return (0);
}
