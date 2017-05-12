/*
** my_revstr.c for revstr in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_04
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 15:10:05 2015 Alexis Viguié
** Last update Mon Oct  5 16:48:45 2015 Alexis Viguié
*/

char	*my_revstr(char *str)
{
  int	counter;
  int	revvar;
  char	counter2;

  counter = 0;
  counter2 = 0;
  revvar = 0;
  while (str[counter] != '\0')
    counter++;
  counter--;
  while (counter2 < counter)
    {
      revvar = str[counter2];
      str[counter2] = str[counter];
      str[counter] = revvar;
      counter2++;
      counter--;
    }
  return (str);
}
