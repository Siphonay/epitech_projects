/*
** my_getnbr.c for 42sh in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jun  4 18:47:41 2016 Alexis Viguié
** Last update Sat Jun  4 18:53:36 2016 Alexis Viguié
*/

int	my_getnbr(const char *str)
{
  int	counter;
  int	result;
  int	negative;

  counter = result = 0;
  negative = 1;
  while ((str[counter] < '0' || str[counter] > '9') && str[counter])
    counter++;
  if (counter && str[counter - 1] == '-')
    negative = -1;
  while (str[counter] >= '0' && str[counter] <= '9')
    {
      result = result * 10 + str[counter] - '0';
      counter++;
    }
  return (result * negative);
}
