/*
** my_putstr.c for 512 in /home/heurta_s/rendu/after_pool/B2/COLLES/CPE_colle_semaine3/src
** 
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
** 
** Started on  Tue May 10 22:41:16 2016 Stanislav HEURTAULT
** Last update Tue May 10 22:43:35 2016 Stanislav HEURTAULT
*/

#include <unistd.h>

void	my_putstr(char *str, int fd)
{
  int	nb;

  nb = 0;
  while (str[nb] != '\0')
    {
      write(fd, &str[nb], 1);
      nb++;
    }
}
