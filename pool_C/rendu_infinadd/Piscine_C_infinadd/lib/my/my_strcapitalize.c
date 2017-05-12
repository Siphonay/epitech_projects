/*
** my_strupcase.c for strupcase in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_08
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 21:31:45 2015 Alexis Viguié
** Last update Wed Oct 14 18:53:57 2015 Alexis Viguié
*/

char	*my_strcaptitalize(char *str)
{
  int	cntr;
  int	f_check;

  f_check = 1;
  cntr = 0;
  while (str[cntr] != '\0')
    {
      if (f_check = 1)
	{
	  if (str[cntr] > 96 && str[cntr] < 123)
	    {
	      str[cntr] = str[cntr] - 32;
	    }
	  f_check = 0;
	}
      else if (str[cntr] > 96 && str[cntr] < 123 && str[cntr - 1] == 32)
	str[cntr] = str[cntr] - 32;
      cntr++;
    }
  return (str);
}
