/*
** my_strcmp.c for strcmp in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_06
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 20:20:14 2015 Alexis Viguié
** Last update Mon Oct  5 20:44:19 2015 Alexis Viguié
*/

int	my_strcmp(char *s1, char *s2)
{
  int	counter;
  int	s1_val;
  int	s2_val;

  counter = 0;
  s1_val = 0;
  s2_val = 0;
  while (s1[counter] != '\0')
    {
      s1_val = s1_val + s1[counter];
      counter++;
    }
  counter = 0;
  while (s2[counter] != '\0')
    {
      s2_val = s2_val + s2[counter];
      counter++;
    }
  return (s1_val - s2_val);
}
