/*
** white_rabbit.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Wed Jan  4 10:05:07 2017 Alexis Viguié
** Last update Thu Jan  5 09:34:48 2017 Alexis Viguié
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int	follow_the_white_rabbit(void)
{
  int	random;
  int	total_sum;
  bool	lapin;

  total_sum = 0;
  lapin = false;
  while (!lapin)
    {
      lapin = ((total_sum += (random = (rand() % 37) + 1)) >= 397 ||
	       random == 1 || random == 37);
      if (!(random % 8) || random == 26)
	printf("%s", "arriere\n");
      if ((random >= 4 && random <= 6) || random == 28 ||
	  (random >= 17 && random <= 21))
	printf("%s", "gauche\n");
      if (random == 13 || (random >= 34 && random <= 36))
	printf("%s", "droite\n");
      if (random == 10 || random == 15)
	printf("%s", "devant\n");
    }
  printf("%s", "LAPIN!!!\n");
  return (total_sum);
}
