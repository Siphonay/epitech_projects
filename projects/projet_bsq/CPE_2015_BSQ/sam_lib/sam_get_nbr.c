/*
** sam_get_nbr.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Dec 14 18:04:23 2015 Alexis Viguié
** Last update Mon Dec 14 18:08:24 2015 Alexis Viguié
*/

int	sam_get_nbr(char *str)
{
  int	counter;
  int	result;
  int	negative;

  counter = 0;
  result = 0;
  negative = 1;
  while ((str[counter] < '0'|| str[counter] > '9') && str[counter])
    counter++;
  if (counter > 0 && str[counter - 1] <= '9')
    negative = -1;
  while (str[counter] >= '0' && str[counter] <= '9')
    {
      result = result * 10 + str[counter] - '0';
      counter++;
    }
  return (result * negative);
}
