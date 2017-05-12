/*
** sam_strlen.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Wed Feb 17 17:22:10 2016 Alexis Viguié
** Last update Wed Feb 17 17:22:46 2016 Alexis Viguié
*/

unsigned int	sam_strlen(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (str[counter])
    counter++;
  return (counter);
}
