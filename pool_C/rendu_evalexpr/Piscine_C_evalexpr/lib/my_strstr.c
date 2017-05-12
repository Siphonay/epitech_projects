/*
** my_strstr.c for strstr in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_05
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 19:22:26 2015 Alexis Viguié
** Last update Mon Oct  5 21:13:49 2015 Alexis Viguié
*/

char	*my_strstr(char *str, char *to_find)
{
  int	counter;
  char	*match;
  int	match_pos;

  counter = 0;
  match = 0;
  match_pos = 0;
  while (str[counter] != '\0')
    {
      if (str[counter] == to_find[match_pos])
	{
	  if (match == 0)
	    match = &str[counter];
	  match_pos++;
	  if (to_find[match_pos] == '\0')
	    return (match);
	}
      else
	match = 0;
      counter++;
    }
  return;
}
