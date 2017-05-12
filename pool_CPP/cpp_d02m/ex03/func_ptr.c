/*
** func_ptr.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m/ex03
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 15:34:01 2017 Alexis Viguié
** Last update Thu Jan  5 16:24:02 2017 Alexis Viguié
*/

#include <string.h>
#include <unistd.h>
#include "func_ptr_enum.h"
#include "func_ptr.h"

void	print_normal(char *str)
{
  write(1, str, strlen(str) * sizeof(char));
  write(1, "\n", sizeof(char));
}

void	print_reverse(char *str)
{
  int	counter;

  counter = strlen(str);
  while (counter)
    {
      counter--;
      write(1, &str[counter], sizeof(char));
    }
  write(1, "\n", sizeof(char));
}

void	print_upper(char *str)
{
  int	counter;
  char	curchar;

  counter = 0;
  while (str[counter])
    {
      curchar = str[counter];
      if (curchar >= 'a' && curchar <= 'z')
	curchar = curchar - 'a' + 'A';
      write(1, &curchar, sizeof(char));
      counter++;
    }
  write(1, "\n", sizeof(char));
}

void	print_42(char *str)
{
  (void)str;
  write(1, "42\n", 3 * sizeof(char));
}

void		do_action(t_action action, char *str)
{
  print_func	pfunc[4];

  pfunc[PRINT_NORMAL] = print_normal;
  pfunc[PRINT_REVERSE] = print_reverse;
  pfunc[PRINT_UPPER] = print_upper;
  pfunc[PRINT_42] = print_42;
  pfunc[action](str);
}
