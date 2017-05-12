/*
** my_is_alpha.c for my transformer in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 09:41:25 2015 Alexis Viguié
** Last update Fri Dec 18 09:45:10 2015 Alexis Viguié
*/

int	my_is_alpha(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      if ((str[counter] < 'A' || str[counter] > 'Z') &&
	  (str[counter] < 'a' || str[counter] > 'z'))
	{
	  return (0);
	}
      counter++;
    }
  return (1);
}
