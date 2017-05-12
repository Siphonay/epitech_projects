/*
** requirement.c for projTester.c in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jun 22 09:41:41 2016 Alexis Viguié
** Last update Sat Jun 25 11:01:04 2016 Alexis Viguié
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void	my_ps_synthesis()
{
  pid_t	pid;
  int	child_ret;

  pid = fork();
  if (pid < 0)
    exit(84);
  else if (!pid)
    execlp("ps", "", (char*)NULL);
  else
    wait(&child_ret);
}
