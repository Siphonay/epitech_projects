/*
** server_main.c for  in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Feb  8 17:02:08 2016 Alexis Viguié
** Last update Mon Feb  8 17:50:14 2016 Alexis Viguié
*/

#include <signal.h>
#include <unistd.h>
#include "sam.h"

void	usr_handler(int sig)
{
  if (sig == SIGUSR2)
    sam_putstr("Catched SIGUSR2!\n", SAM_STDIN);
  else
    sam_putstr("Catched SIGUSR1!\n", SAM_STDIN);
}

int	main()
{
  sam_putstr("PID ", SAM_STDIN);
  sam_putnbr(getpid(), SAM_STDIN);
  sam_putstr("\n", SAM_STDIN);
  while (1)
    {
      signal(SIGUSR2, usr_handler);
      signal(SIGUSR1, usr_handler);
    }
}
