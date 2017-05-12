/*
** xo_exit.c for tic tac toe in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Feb  9 09:23:04 2016 Alexis Viguié
** Last update Wed Feb 10 09:18:38 2016 Alexis Viguié
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include "xo.h"

void	exit_wintoosmall()
{
  endwin();
  fprintf(stderr, WTS_M);
  exit(1);
}
