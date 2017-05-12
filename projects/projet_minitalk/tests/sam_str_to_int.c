/*
** sam_str_to_int.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Feb  4 15:42:00 2016 Alexis Viguié
** Last update Wed Feb 17 15:21:57 2016 Alexis Viguié
*/

int		sam_str_to_int(char *str)
{
  unsigned int	counter;
  int		ret_int;
  int		ret_neg;

  counter = 0;
  ret_int = 0;
  while (str[counter] < '0' && str[counter] > '9' && str[counter] != '-'
	 && str[counter])
    counter++;
  if (str[counter] == '-')
    ret_neg = -1;
  else
    ret_neg = 1;
  while ((str[counter] >= '0' && str[counter] <= '9') && str[counter])
    {
      ret_int = (ret_int * 10) + (str[counter] - '0');
      counter++;
    }
  return (ret_int * ret_neg);
}
