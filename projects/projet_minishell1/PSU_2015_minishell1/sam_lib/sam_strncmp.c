/*
** sam_strncmp.c for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Jan 17 18:38:29 2016 Alexis Viguié
** Last update Sun Jan 17 19:17:17 2016 Alexis Viguié
*/

int		sam_strncmp(char *pstring_1, char *pstring_2, unsigned int c_lim)
{
  unsigned int	counter;
  int		p1_val;
  int		p2_val;

  counter = 0;
  p1_val = 0;
  p2_val = 0;
  while (counter < c_lim && pstring_1[counter] && pstring_2[counter])
    {
      p1_val += pstring_1[counter];
      p2_val += pstring_2[counter];
      counter++;
    }
  return (p1_val - p2_val);
}
