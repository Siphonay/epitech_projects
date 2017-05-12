/*
** sam_bin_to_char.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Mon Feb 15 17:39:43 2016 Alexis Viguié
** Last update Wed Feb 17 15:34:04 2016 Alexis Viguié
*/
#include <stdio.h>
unsigned char	sam_bin_to_char(char *bin_str)
{
  unsigned int	counter;
  unsigned int	bin_val;
  unsigned char	ret_char;

  bin_val = 1;
  counter = (ret_char = 0);
  while (bin_str[counter + 1])
    {
      bin_val *= 2;
      counter++;
    }
  counter = 0;
  while (bin_str[counter])
    {
      if (bin_str[counter] - '0')
	ret_char += bin_val;
      bin_val /= 2;
      counter++;
    }
  return (ret_char);
}
