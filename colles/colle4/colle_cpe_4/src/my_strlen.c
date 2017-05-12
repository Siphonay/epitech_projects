/*
** my_strlen.c for my transformer in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec 18 09:14:35 2015 Alexis Viguié
** Last update Fri Dec 18 09:15:06 2015 Alexis Viguié
*/

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}
