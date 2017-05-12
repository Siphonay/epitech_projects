/*
** my_putchar.c for my_putchar in /home/zaza/rendu/PSU_2015_my_printf/
**
** Made by Thibault Derbré
** Login   <derbre_t@epitech.eu>
**
** Started on  Thu Nov  5 18:28:53 2015 Thibault Derbré
** Last update Sat Nov 14 15:32:25 2015 Thibault Derbré
*/

#include "my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
