/*
** cat.c for my cat in /home/viguie_a/rendu_j12/Piscine_C_J12
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Tue Oct 13 15:04:25 2015 Alexis Viguié
** Last update Wed Oct 14 21:58:01 2015 Alexis Viguié
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
  return (putfile(ac, av));
}

char    file_to_str(int fd, int buffs, char readstr[30720], int strsize)[30720]
{
  char  cfrd[buffs + 1];
  int   counter;

  read(fd, cfrd, buffs);
  counter = 0;
  while (cfrd[counter] != '\0')
    {
      readstr[strsize] = cfrd[counter];
      counter++;
      strsize++;
    }
  return (readstr);
}

int	putfile(int ac, char **av)
{
  int	counter;
  int	fd;
  int	buffs;
  char	readstr[30720];
  int	strsize;

  counter = 0;
  strsize = 0;
  while (counter < ac)
    {
      if (ac == 1)
	fd = 0;
      else
	fd = open(av[counter], O_RDONLY);
      if (fd == -1)
        {
          write(2, "error: file not found\n", 22);
          return (1);
        }
      buffs = lseek(fd, 0, SEEK_END);
      lseek(fd, 0, SEEK_SET);
      readstr = file_to_str(fd, buffs, readstr, strsize);
      strsize = strsize + buffs + 1;
      counter++;
    }
  close (fd);
  my_putstr(readstr);
  return (0);
}
