/*
** parser.c for parser in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Oct 29 15:41:48 2015 Alexis Viguié
** Last update Fri Oct 30 17:50:56 2015 Alexis Viguié
*/

char	*simplify_num(char *num, char *base)
{
  int	counter;
  int	counter2;
  char	*res;

  counter = 0;
  while (num[counter] ==  base[0] && num[counter] != '\0')
    counter++;
  if (num[counter] == '\0' && num[counter - 1] == base[0])
    {
      res = malloc(sizeof(char) * 2);
      res[0] = base[0];
      res[1] = '\0';
    }
  else
    {
      res = malloc(((my_strlen(num) - counter) + 1) * sizeof(char));
      counter2 = 0;
      while (num[counter - 1] != '\0')
	{
	  res[counter2] = num[counter];
	  counter++;
	}
    }
  return (res);
}

  int	bistro_parser(char **nums, char **ops_s, char *base, char *ops)
{
  int	counter;

  counter = 0;
  while (nums[counter] != '\0')
    {
      if (nums[counter][0] == base[0])
	simplify_num(nums[counter], bas));
      counter++;
    }
}
