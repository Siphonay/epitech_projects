/*
** findL.c for CPE_colle_semaine1 in /home/simon/CPE_colle_semaine1/lib
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 15:48:58 2016 Simon Pedrono
** Last update Tue Apr 26 17:58:44 2016 Simon Pedrono
*/

int	my_findletterL(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[0] == '-' && str[1] != '\0')
	{
	  if (str[i] == 'L')
	    return (1);
	}
      i++;
    }
  return (0);
}
