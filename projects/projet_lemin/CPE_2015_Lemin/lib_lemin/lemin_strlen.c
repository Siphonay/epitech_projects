/*
** lemin_strlen.c for lib lemin in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Apr 20 16:16:32 2016 Alexis Viguié
** Last update Wed Apr 20 16:17:11 2016 Alexis Viguié
*/

unsigned int	lemin_strlen(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}
