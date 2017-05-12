/*
** tablen.c for rush mai in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat May 14 13:51:05 2016 Alexis Viguié
** Last update Sat May 14 15:40:15 2016 Alexis Viguié
*/

#include <stddef.h>

size_t		marvin_tablen(char **tab)
{
  size_t	ret_size;

  ret_size = 0;
  while (tab[ret_size])
    ret_size++;
  return (ret_size);
}
