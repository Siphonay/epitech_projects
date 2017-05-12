/*
** my_getnbr.c for colle cocktail in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Dec  2 14:06:38 2015 Alexis Viguié
** Last update Wed Dec  2 14:34:46 2015 Alexis Viguié
*/

int	my_get_nbr(char *str)
{
  int	counter;
  int	res;
  int	neg;

  counter = 0;
  res = 0;
  neg = 1;
  while ((str[counter] < '0' || str[counter] > '9') && str[counter])
    counter++;
  if (counter > 0 && str[counter - 1] == '-')
    neg = -1;
  while (str[counter] >= '0' && str[counter] <= '9')
    {
      res = res * 10 + str[counter] - '0';
      counter++;
    }
  return (res * neg);
}
