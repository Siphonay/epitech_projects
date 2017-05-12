/*
** my_getnbr.c for temp_getnbr in /home/viguie_a/rendu_j07/Piscine_C_J07/lib/my
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Tue Oct  6 14:16:10 2015 Alexis Viguié
** Last update Mon Oct 19 20:58:11 2015 Alexis Viguié
*/

int	my_getnbr(char *str)
{
  int	counter;
  int	res;
  int	neg;

  counter = 0;
  res = 0;
  neg = 1;
  while ((str[counter] < '0' || str[counter] > '9') && str[counter] != '\0')
    {
      counter++;
    }
  if (counter > 0 && str[counter - 1] == '-')
    neg = -1;
  while (str[counter] != '\0' && (str[counter] >= '0' && str[counter] <= '9'))
    {
      res = (res * 10) + (str[counter] - '0');
      counter++;
    }
  res = res * neg;
  if (counter == 0)
    return (-1);
  else
    return (res);
}
