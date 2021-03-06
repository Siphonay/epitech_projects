/*
** my_strncpy.c for strncpy in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_02
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 10:35:41 2015 Alexis Viguié
** Last update Mon Oct  5 15:08:13 2015 Alexis Viguié
*/

int     my_strlen(char *str)
{
  int   counter;

  counter = 0;
  while (*str != '\0')
    {
      str++;
      counter++;
    }
  return (counter);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	counter;

  counter = 0;
  while (counter < n && src[counter] != '\0')
    {
      dest[counter] = src[counter];
      counter++;
    }

  while (counter < n + 1)
    {
      dest[counter] = '\0';
      counter++;
    }
  return (dest);
}
