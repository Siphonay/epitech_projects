/*
** sam_putstr.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 18 21:11:26 2016 Alexis Viguié
** Last update Mon Jan 18 21:12:58 2016 Alexis Viguié
*/

#include <unistd.h>
#include "sam.h"

void	sam_putstr(char *str)
{
  write(1, str, sam_strlen(str));
}

void	sam_putstr_err(char *str)
{
  write(1, str, sam_strlen(str));
}
