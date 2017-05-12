/*
** my_strncmp.c for strncmp in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_07
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 20:20:14 2015 Alexis Viguié
** Last update Mon Oct  5 21:24:19 2015 Alexis Viguié
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	counter;
  int	s1_val;
  int	s2_val;

  counter = 0;
  s1_val = 0;
  s2_val = 0;
  while (s1[counter] != '\0' || counter < n)
    {
      s1_val = s1_val + s1[counter];
      counter++;
    }
  counter = 0;
  while (s2[counter] != '\0' || counter < n)
    {
      s2_val = s2_val + s2[counter];
      counter++;
    }
  return (s1_val - s2_val);
}
