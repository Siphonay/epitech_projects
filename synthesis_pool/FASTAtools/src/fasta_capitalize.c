/*
** fasta_capitalize.c for FASTAtools in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 20 19:23:10 2016 Alexis Viguié
** Last update Mon Jun 20 19:24:18 2016 Alexis Viguié
*/

char	*str_capitalize(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter])
    {
      if (str[counter] >= 'a' && str[counter] <= 'z')
	str[counter] = str[counter] - 'a' + 'A';
      counter++;
    }
  return (str);
}
