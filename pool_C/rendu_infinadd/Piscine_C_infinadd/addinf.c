/*
** addinf.c for infadd in /home/viguie
**
** Made by Alexis Viguié
** Login   <viguie@epitech.net>
**
** Started on  Tue Oct 20 20:29:53 2015 Alexis Viguié
** Last update Wed Oct 21 01:10:28 2015 Alexis Viguié
*/

#include <stdlib.h>

char	*addinf(char **nums)
{
  int	counter;
  int	addresult;
  int	remainder;
  char	*numb1;
  char	*numb2;
  char	*resadd;

  numb1 = my_revstr(nums[0]);
  numb2 = my_revstr(nums[1]);
  resadd = malloc(my_strlen(numb1) + 1 * sizeof(char));
  counter = 0;
  remainder = 0;
  while (numb1[counter] != '\0')
    {
      if (numb2 [counter] == 'Z')
	addresult = numb1[counter] + remainder;
      else
	addresult = numb1[counter] + numb2[counter] + remainder;
      if (addresult > 9)
	{
	  resadd[counter] = (addresult % 10) + '0';
	  remainder = (addresult - (addresult % 10)) / 10;
	}
      else
	resadd[counter] = addresult + '0';
      counter++;
    }
  return (my_revstr(resadd));
}
