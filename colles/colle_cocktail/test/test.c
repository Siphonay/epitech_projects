/*
** test.c for test in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Dec  2 14:51:31 2015 Alexis Viguié
** Last update Wed Dec  2 15:07:46 2015 Alexis Viguié
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      write(1, &str[counter], 1);
      counter++;
    }
}

int	main()
{
  char	*buffer;

  buffer = malloc(2048 * sizeof(char));
  while (!(buffer[0] == '0' && buffer[1]  == '\n'))
    {
      buffer = malloc(2048 * sizeof(char));
      read(0, buffer, 2048);
      my_putstr(buffer);
    }
  free(buffer);
  return (0);
}
