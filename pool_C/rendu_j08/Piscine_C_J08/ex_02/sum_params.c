/*
** sum_params.c for sum params in /home/viguie_a/rendu_j08/Piscine_C_J08/ex_02
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Wed Oct  7 11:46:09 2015 Alexis Viguié
** Last update Wed Oct  7 16:01:21 2015 Alexis Viguié
*/

#include <stdlib.h>

int	sum_params_len(int argc, char **argv)
{
  int	counter;
  int	counter2;
  int	parlen;

  counter = 0;
  parlen = 0;
  while (counter < argc)
    {
      counter2 = 0;
      while (counter2 < my_strlen(argv[counter]))
        {
          parlen++;
          counter2++;
        }
      counter++;
    }
  return (parlen);
}

char	*sum_params(int argc, char **argv)
{
  char	*dest;
  int	counter;
  int	counter2;
  int	strpos;

  counter = 0;
  strpos = 0;
  dest = malloc(sum_params_len(argc, argv));
  while (counter < argc)
    {
      counter2 = 0;
      while (counter2 < my_strlen(argv[counter]))
	{
	  dest[strpos] = argv[counter][counter2];
	  counter2++;
	  strpos++;
	}
      dest[strpos] = '\n';
      strpos++;
      counter++;
    }
  dest[strpos - 1] = '\0';
  return (dest);
}
