/*
** sam_strlen.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jan 18 21:10:12 2016 Alexis Viguié
** Last update Mon Jan 18 21:39:39 2016 Alexis Viguié
*/

unsigned int	sam_strlen(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}
