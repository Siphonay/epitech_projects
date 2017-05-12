/*
** isnum.c for in /home/simon/CPE_colle_semaine1/srcs
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 15:43:58 2016 Simon Pedrono
** Last update Tue Apr 26 17:58:40 2016 Simon Pedrono
*/

int	my_isnum(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	nb = 1;
      i++;
    }
  return (nb);
}
