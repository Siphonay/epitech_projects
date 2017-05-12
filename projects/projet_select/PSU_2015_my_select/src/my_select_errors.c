/*
** my_select_errors.c for my select in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Dec 13 18:03:58 2015 Alexis Viguié
** Last update Mon Dec 14 15:36:46 2015 Alexis Viguié
*/

#include <stdlib.h>
#include <ncurses.h>
#include "sam.h"

void	arg_err(char **av)
{
  sam_putstr_err("usage: ");
  sam_putstr_err(av[0]);
  sam_putstr_err(" string1 [string_2 ... string_n]\n");
  clear();
  endwin();
  exit(1);
}

void	mllc_err()
{
  sam_putstr_err("error: malloc failed\n");
  exit(42);
}

void	wsize_err()
{
  sam_putstr_err("error: window size too small\n");
  clear();
  endwin();
  exit(2);
}
