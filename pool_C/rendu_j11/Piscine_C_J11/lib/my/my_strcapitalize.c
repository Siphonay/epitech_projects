/*
** my_strupcase.c for strupcase in /home/viguie_a/rendu_j06/Piscine_C_J06/ex_08
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct  5 21:31:45 2015 Alexis Viguié
** Last update Tue Oct  6 15:20:34 2015 Alexis Viguié
*/

char	*my_strcaptitalize(char *str)
{
  int	counter;
  int	f_check;

  f_check = 1;
  counter = 0;
  while (str[counter] != '\0')
    {
      if (f_check = 1)
	{
	  if (str[counter] > 96 && str[counter] < 123)
	    {
	      str[counter] = str[counter] - 32;
	    }
	  f_check = 0;
	}
      else if (str[counter] > 96 && str[counter] < 123 && str[counter - 1] == 32)
	str[counter] = str[counter] - 32;
      counter++;
    }
  return (str);
}
