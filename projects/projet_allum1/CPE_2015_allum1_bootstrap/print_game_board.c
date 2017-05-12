/*
** print_game_board.c for allum1 bootstrap in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Fri Feb 12 10:57:22 2016 Alexis Viguié
** Last update Fri Feb 12 12:00:22 2016 Alexis Viguié
*/

#include <unistd.h>

void		printspaces(unsigned int counter)
{
  unsigned int	counter2;

  counter2 = 0;
  while (counter2 < (7 - counter) / 2)
    {
      write(1, " ", 1);
      counter2++;
    }
}

void		print_game_board()
{
  unsigned int	counter;
  unsigned int	counter2;

  counter = 1;
  while (counter <= 7)
    {
      printspaces(counter);
      counter2 = 0;
      while (counter2 < counter)
	{
	  write(1, "|", 1);
	  counter2++;
	}
      write(1, "\n", 1);
      counter += 2;
    }
}

void		print_board_in_a_pretty_frame()
{
  unsigned int	counter;
  unsigned int	counter2;

  write(1, "*********\n", 10);
  counter = 1;
  while (counter <= 7)
    {
      write(1, "*", 1);
      printspaces(counter);
      counter2 = 0;
      while (counter2 < counter)
	{
	  write(1, "|", 1);
	  counter2++;
	}
      printspaces(counter);
      write(1, "*\n", 2);
      counter += 2;
    }
  write(1, "*********\n", 10);
}

 int	main()
 {
   print_game_board();
   print_board_in_a_pretty_frame();
   return (0);
 }
