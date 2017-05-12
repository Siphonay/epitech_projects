/*
** main.c for colle 2 in /home/viguie_a/rendu_colle2
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Sat Oct 10 15:44:54 2015 Alexis Viguié
** Last update Sat Oct 10 21:50:49 2015 Alexis Viguié
*/

#include <stdlib.h>

int dispadd(char *str, int counter, int speed)
{
  char	stock;

  while (counter < my_strlen(str) / 2)
    {
      stock = str[counter];
      str[counter] = str[counter + (my_strlen(str) / 2)];
      str[counter + (my_strlen(str) / 2)] = stock;
      my_putchar('\r');
      my_putstr(str);
      usleep(speed);
      counter++;
    }
  return (counter);
}

int	dispsoustr(char *str, int counter, int speed)
{
  char	stock;

  while (str[counter] > 0)
    {
      stock = str[counter];
      str[counter] = str[counter + (my_strlen(str) / 2)];
      str[counter + (my_strlen(str) / 2)] = stock;
      my_putchar('\r');
      my_putstr(str);
      usleep(speed);
      counter--;
    }
  return (counter);
}

void	disp_afftext(char *str, int speed)
{
  int	soustr;
  int	counter;

  soustr = 0;
  counter = 0;
  my_putstr(str);
  usleep(speed);
  while (1)
    {
      if (soustr)
        {
          soustr = 0;
          counter = dispsoustr(str, counter, speed);
          counter++;
        }
      else
        {
          soustr = 1;
          counter = dispadd(str, counter, speed);
          counter--;
        }
    }
}

void	main(int argv, char **argc)
{
  int	counter;
  char	*str;
  int	speed;

  if (argv == 2)
    speed = 100000;
  else if (argv == 3)
    speed = my_getnbr(argc[2]);
  else
    {
      my_putstr(argc[0]);
      my_putstr(" word [speed]\n");
      return;
    }
  str = malloc(my_strlen(argc[1]) * 2 * sizeof(char));
  counter = 0;
  while (counter < (my_strlen(argc[1]) * 2))
    {
      if (counter < my_strlen(argc[1]))
	str[counter] = argc[1][counter];
      else
	str[counter] = ' ';
      counter++;
    }
  disp_afftext(str, speed);
}
