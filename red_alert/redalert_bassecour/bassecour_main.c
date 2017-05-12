/*
** bassecour_main.c for red alert basse cour in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Apr 25 09:18:42 2016 Alexis Viguié
** Last update Mon Apr 25 09:51:03 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bassecour.h"

int		main(void)
{
  unsigned int	number_animals;
  unsigned int	number_things;
  unsigned int	counter;
  char		species[51];
  char		things[11];

  scanf("%d", &number_animals);
  counter = 0;
  while (counter < number_animals)
    {
      scanf("%s", species);
      counter++;
    }
  counter = 0;
  while (counter < number_animals)
    {
      scanf("%s%d", things, &number_things);
      counter++;
    }
  printf("answer\n");
  return (0);
}
