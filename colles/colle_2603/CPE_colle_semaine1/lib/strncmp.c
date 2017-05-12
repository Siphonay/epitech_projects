/*
** strncmp.c for CPE_colle_semaine1 in /home/simon/CPE_colle_semaine1/lib
**
** Made by Simon Pedrono
** Login   <simon@epitech.net>
**
** Started on  Tue Apr 26 17:02:29 2016 Simon Pedrono
** Last update Tue Apr 26 17:58:24 2016 Simon Pedrono
*/

int	my_strcmp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0')
    {
      i++;
      if (str[i] == '\0')
	return (1);
    }
  return (0);
}
