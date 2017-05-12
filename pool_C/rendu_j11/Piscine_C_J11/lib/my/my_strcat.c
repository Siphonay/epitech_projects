/*
** my_strcat.c for  in /home/viguie_a/rendu_j07/Piscine_C_J07/lib/my
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Tue Oct  6 17:18:52 2015 Alexis Viguié
** Last update Tue Oct  6 17:34:46 2015 Alexis Viguié
*/

char	*my_strcat(char *dest, char *src)
{
  int	dest_len;
  int	counter;

  counter = 0;
  dest_len = my_strlen(dest);
  while (counter < my_strlen(src))
    {
      dest[dest_len + counter] = src[counter];
      counter++;
    }
    dest[dest_len + counter] = '\0';

    return (dest);
}
