/*
** my_tab.c for check the tab in /home/ruffetm/rendu/CPE/CPE_2015_corewar/my_asm
**
** Made by Mathieu RUFFET
** Login   <ruffetm@epitech.net>
**
** Started on  Fri Mar 25 15:54:21 2016 Mathieu RUFFET
** Last update Wed Mar 30 09:00:05 2016 Victor Herlin
*/

#include "asm.h"

char	**clean_tab_first_spaces(char **tab)
{
  int	i;
  int	j;
  int	new;

  i = 0;
  while (tab[i])
    {
      j = 0;
      new = 0;
      while (tab[i][j] == ' ' || tab[i][j] == '\t')
	j++;
      while (tab[i][j])
	{
	  tab[i][new] = tab[i][j];
	  j++;
	  new++;
	}
      while (new < my_strlen(tab[i]))
	{
	  tab[i][new] = '\0';
	  new++;
	}
      i++;
    }
  return (tab);
}

int	check_the_tab(char **tab)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((my_strncmp(tab[0], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING))) == 0)
    {
      while (tab[0][i] != '\0')
	i++;
      if (i > 134)
	return (1);
      if ((my_strncmp(tab[1], COMMENT_CMD_STRING,
		      my_strlen(COMMENT_CMD_STRING))) == 0)
	{
	  while (tab[1][j] != '\0')
	    j++;
	  if (j > 2057)
	    return (1);
	}
      return (0);
    }
  else
    return (1);
}
