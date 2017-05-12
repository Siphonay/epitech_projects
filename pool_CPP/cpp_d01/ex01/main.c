/*
** main.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d01/ex01
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Wed Jan  4 14:07:35 2017 Alexis Viguié
** Last update Wed Jan  4 15:49:53 2017 Alexis Viguié
*/

#include <stdbool.h>

void	print_empty_squares(int size, int depth);

bool	is_power_of_three(int num)
{
  if (!num)
    return (false);
  while (!(num % 3))
    n /= 3;
  return (num == 1);
}

int	my_atoi(char *str)
{
  int	res;
  int	counter;

  res = counter = 0;
  while (str[counter])
    {
      res = res * 10 + (str[counter] - '0');
      counter++;
    }
  return (res);
}

int	main(int ac, char **av)
{
  if (ac < 3 || !(is_a_power_of_three(my_atoi(av[1]))) ||
      my_atoi(av[2]) > my_atoi(av[1]))
    return (84);
  print_empty_squares(my_atoi(av[1]), my_atoi[2]);
  return (0);
}
