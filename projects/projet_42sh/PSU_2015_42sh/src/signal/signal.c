/*
** signal.c for PSU_2015_42sh
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Sat Jun 04 15:14:54 2016 pedron_s
** Last update	Sun Jun 05 21:59:57 2016 pedron_s
*/

#include <signal.h>
#include <unistd.h>
#include "mysh.h"

void	my_backend()
{
  my_putchar('\n');
  my_putstr("\033[1;34m[42sh] ->\033[0m");
}

void	init_signal()
{
  if ((isatty(STDIN_FILENO)) != 0)
    signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGTERM, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  signal(SIGTTOU, SIG_IGN);
}
