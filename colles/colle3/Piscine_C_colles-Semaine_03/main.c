/*
** main.c for colle 3 in /home/sam/colle3/Piscine_C_colles-Semaine_03
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Oct 25 00:57:49 2015 Alexis Viguié
** Last update Sun Oct 25 02:39:59 2015 Alexis Viguié
*/

#include <unistd.h>
#include "colle3.h"
#include "my.h"
#include "glue.h"

int	main(int ac, char **av)
{
  char	buff[BUFF_SIZE + 1];
  int	len;
  int	err;

  while ((len = read(0, buff, BUFF_SIZE)) > 0)
    {
      if (len != 0)
	{
	  buff[len] = 0;
	}
    }
  err = glue_func(buff);
  my_putchar('\n');
  return (err);
}
