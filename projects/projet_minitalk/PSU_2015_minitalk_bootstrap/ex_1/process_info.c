/*
** process_info.c for minitalk bootstrap in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Feb  5 10:32:23 2016 Alexis Viguié
** Last update Fri Feb  5 10:41:58 2016 Alexis Viguié
*/

#include <signal.h>

int		main()
{
  int		pid_num;
  siginfo_t	*signal_info;

  if (sigaction(pid_num, signal_info, SA_SIGINFO) == -1)
    return (1);
}
