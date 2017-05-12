/*
** client_send.c for minitalk client in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Wed Feb 17 17:07:39 2016 Alexis Viguié
** Last update Thu Feb 18 16:52:12 2016 Alexis Viguié
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "mtk_common.h"
#include "mtk_client.h"
#include "sam.h"

int	send_handshake(int pid)
{
  return ((kill(pid, SIGUSR1) == -1) &&
	  (usleep(USLEEP_TIME) == -1) &&
	  (kill(pid, SIGUSR2) == -1) &&
	  (usleep(USLEEP_TIME) == -1));
}

int	send_zero(int pid)
{
  return ((kill(pid, SIGUSR1) == -1) &&
	  (usleep(USLEEP_TIME) == -1));
}

int	send_one(int pid)
{
  return ((kill(pid, SIGUSR2) == -1) &&
	  (usleep(USLEEP_TIME) == -1));
}

void		complete_zeroes(char *bin_char, int pid)
{
  unsigned int	counter;

  counter = 0;
  while (counter < (8 - sam_strlen(bin_char)))
    {
      if (send_zero(pid))
	client_fail_free_and_exit(bin_char);
      counter++;
    }
}

void		client_send_char(char tosend_char, int pid)
{
  char		*bin_char;
  unsigned int	counter;

  bin_char = sam_int_to_bin(tosend_char);
  if (send_handshake(pid))
    client_fail_free_and_exit(bin_char);
  complete_zeroes(bin_char, pid);
  counter = 0;
  while (bin_char[counter])
    {
      if (bin_char[counter] - '0')
	{
	  if (send_one(pid))
	    client_fail_free_and_exit(bin_char);
	}
      else
	{
	  if (send_zero(pid))
	    client_fail_free_and_exit(bin_char);
	}
      counter++;
    }
  free(bin_char);
}
