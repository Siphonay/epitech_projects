/*
** close_flist.c for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 15:12:29 2016 Alexis Viguié
** Last update Sat Jan  9 15:14:28 2016 Alexis Viguié
*/

#include <stdio.h>
#include <stdlib.h>

void	close_flist(FILE **file_list, int filenum)
{
  int	counter;

  counter = 0;
  while (counter < filenum)
    {
      fclose(file_list[counter]);
      counter++;
    }
  free(file_list);
}
