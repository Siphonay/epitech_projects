/*
** glue_func.c for colle 3 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Oct 25 01:43:15 2015 Alexis Viguié
** Last update Sun Oct 25 02:45:22 2015 Alexis Viguié
*/

#include "glue.h"
#include "my.h"
#include "colle3.h"

int	get_colle_num(char edges[3])
{
  if (edges[0] == 'B')
    return (6);
  if (edges[0] == 'o')
    return (1);
  if (edges[0] == '/' || edges[0] == '*')
    return (2);
  if (edges[0] == 'A')
    {
      if (edges[2] == 'A')
	return (5);
      if (edges[1] == 'A')
	return (3);
      return (4);
    }
  return (7);
}

int	multi_sq_aff(int len, int hei)
{
  my_putstr("[colle 1-3] ");
  my_put_nbr(len);
  my_putchar(' ');
  my_put_nbr(hei);
  my_putstr(" || [colle 1-4] ");
  my_put_nbr(len);
  my_putchar(' ');
  my_put_nbr(hei);
  my_putstr(" || [colle 1-5] ");
  my_put_nbr(len);
  my_putchar(' ');
  my_put_nbr(hei);
}

int	aff_colle_num(int len, int hei, char edges[3], char *buff)
{
  if (get_colle_num(edges) == 7)
    {
      my_strerr("input error");
      return (1);
    }
  else if (get_colle_num(edges) == 6)
    {
      my_putstr(buff);
      multi_sq_aff(len, hei);
    }
  else
    {
      my_putstr(buff);
      my_putstr("[colle1-");
      my_put_nbr(get_colle_num(edges));
      my_putstr("] ");
      my_put_nbr(len);
      my_putchar(' ');
      my_put_nbr(hei);
    }
  return (0);
}

int	glue_func(char *buff)
{
  int	counter;
  char	edges[3];
  int	len;
  int	height;
  int	gotlen;

  counter = 0;
  len = 0;
  height = 0;
  gotlen = 0;
  edges[0] = buff[counter];
  while (buff[counter] != '\0')
    {
      if (buff[counter] == '\n')
	{
	  height++;
	  if (!(gotlen))
	    edges[1] = buff[counter - 1];
	  gotlen = 1;
	}
      if (!(gotlen))
	len++;
      counter++;
    }
  edges[2] = buff[counter - 2];
  return (aff_colle_num(len, height, edges, buff));
}
