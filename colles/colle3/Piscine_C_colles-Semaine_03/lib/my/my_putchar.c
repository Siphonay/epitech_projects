/*
** my_putchar.c for putchar in /home/viguie_a/rendu_j07/Piscine_C_J07/lib
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Tue Oct  6 13:28:43 2015 Alexis Viguié
** Last update Sat Oct 24 23:38:43 2015 Alexis Viguié
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
