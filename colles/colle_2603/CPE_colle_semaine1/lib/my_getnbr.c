/*
** my_getnbr.c for tree in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Apr 26 14:18:42 2016 Alexis Viguié
** Last update Tue Apr 26 17:58:38 2016 Simon Pedrono
*/

int		my_getnbr(char *str)
{
  unsigned int	counter;
  int		ret_nbr;
  int		negative;

  counter = ret_nbr = 0;
  while (str[counter] < '0' && str[counter] > '9' && str[counter] != '-' &&
	 str[counter])
    counter++;
  if (str[counter] == '-')
    negative = -1;
  else
    negative = 1;
  while ((str[counter] >= '0' && str[counter] < '9') && str[counter])
    {
      ret_nbr = (ret_nbr * 10) + (str[counter] - '0');
      counter++;
    }
  return (ret_nbr * negative);
}
