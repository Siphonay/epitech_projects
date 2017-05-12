/*
** add_operations.c for infadd in /home/viguie_a/rendu_infinadd/Piscine_C_infinadd
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Mon Oct 19 22:09:02 2015 Alexis Viguié
** Last update Wed Oct 21 01:10:34 2015 Alexis Viguié
*/

#include <stdlib.h>

char	*xfiller(char *largerstr, char *smallerstr)
{
  char	*strret;
  int	counter;

  strret = calloc(my_strlen(largerstr) + 1, sizeof(char));
  strret = my_strcpy(strret, smallerstr);
  counter = 0;
  while (largerstr[counter] != '\0')
    {
      if (strret[counter] == '\0')
	strret[counter] = 'Z';
      counter++;
    }
  return (strret);
}

char	**setstrings(char **av, int param1len, int param2len)
{
  char	**nums;

  nums = malloc(2);
  if (param1len > param2len)
    {
      nums[0] = av[1];
      nums[1] = xfiller(av[1], av[2]);
    }
  else if (param2len > param1len)
    {
      nums[0] = av[2];
      nums[1] = xfiller(av[2], av[1]);
    }
  else
    {
      nums[0] = av[1];
      nums[1] = av[2];
    }
  return (nums);
}

char	**setnumstr(char **av)
{
  int	param1len;
  int	param2len;

  param1len = my_strlen(av[1]);
  param2len = my_strlen(av[2]);
  if (av[1][0] == '-')
      param1len--;
  if (av[2][0] == '-')
      param2len--;
  return (setstrings(av, param1len, param2len));
}
