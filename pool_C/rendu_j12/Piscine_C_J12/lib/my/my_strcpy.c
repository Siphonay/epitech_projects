/*
** my_strcpy.c for strcpy in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_02
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 10:35:41 2015 Alexis Viguié
** Last update Wed Oct 14 18:54:42 2015 Alexis Viguié
*/

char	*my_strcpy(char *dest, char *src)
{
  int	counter;

  counter = 0;
  while (counter < my_strlen(src) - 1)
    {
      dest[counter] = src[counter];
      counter++;
    }
  if (counter < my_strlen(dest) - 1)
      dest[counter] = '\0';
  return (dest);
}
