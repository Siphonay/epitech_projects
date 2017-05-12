/*
** sam_strtablen.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 17:40:27 2016 Alexis Viguié
** Last update Wed Jan 27 17:41:00 2016 Alexis Viguié
*/

unsigned int	sam_strtablen(char **strtab)
{
  unsigned int	counter;

  counter = 0;
  while (strtab[counter])
    counter++;
  return (counter);
}
