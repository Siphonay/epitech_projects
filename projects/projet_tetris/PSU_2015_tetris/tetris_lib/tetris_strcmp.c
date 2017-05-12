/*
** tetris_strcmp.c for tetris lib in /home/sam/Rendu/Projets/projet_tetris/PSU_2015_tetris/tetris_lib
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Mar  3 17:09:35 2016 Alexis Viguié
** Last update Thu Mar  3 17:12:14 2016 Alexis Viguié
*/

#include <stdbool.h>

bool		tetris_strcmp(char *str_1, char *str_2)
{
  unsigned int	counter;

  counter = 0;
  while (str_1[counter] && str_2[counter])
    {
      if (str_1[counter] != str_2[counter])
	return (false);
      counter++;
    }
  return (!str_1[counter] && !str_2[counter]);
}
