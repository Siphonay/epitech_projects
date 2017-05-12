/*
** err.c for tree in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Apr 26 14:42:34 2016 Alexis Viguié
** Last update Tue Apr 26 17:57:54 2016 Simon Pedrono
*/

#include "tree.h"

void	print_usage(t_options st)
{
  my_putstr_err("tree: invalid argument - `");
  my_putchar_err(st.bad);
  my_putstr_err("'.\nusage: tree [-adf] [-L level]\n");
}
