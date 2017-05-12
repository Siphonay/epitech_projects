/*
** my_strncmp.c for my_strncmp in /home/guillaume/Bureau/code/tp/unix/CPE_2015_corewar/src
**
** Made by Guillaume Morin
** Login   <guillaume@epitech.net>
**
** Started on  Tue Mar 22 11:37:54 2016 Guillaume Morin
** Last update Fri Mar 25 17:27:37 2016 Victor Herlin
*/

int	my_strncmp(char *str1, char *str2, unsigned int n)
{
  unsigned int	i;

  i = 0;
  while (i < n)
    {
      if (str1[i] != str2[i])
	return (1);
      i++;
    }
  return (0);
}
