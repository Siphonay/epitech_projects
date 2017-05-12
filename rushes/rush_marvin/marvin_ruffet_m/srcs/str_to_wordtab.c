/*
** strtok.c for strtok in /home/ruffetm/rendu/RUSH/marvin_ruffet_m/srcs
**
** Made by Mathieu RUFFET
** Login   <ruffetm@epitech.net>
**
** Started on  Sat May 14 13:46:40 2016 Mathieu RUFFET
** Last update Sat May 14 16:33:20 2016 Mathieu RUFFET
*/

#include <stdlib.h>
#include <unistd.h>
#include "marvin.h"

char	*my_strnncpy(char *str, int i, int j)
{
  char	*new_str;
  int	curs;

  curs = 0;
  if ((new_str = malloc((j - i + 1) * sizeof(char))) == NULL)
    exit(33);
  while (i != j)
    {
      new_str[curs] = str[i];
      i++;
      curs++;
    }
  new_str[curs] = '\0';
  return (new_str);
}

int	count_word(char *str)
{
  int	i;
  int	word;

  i = 0;
  word = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  if (str[i] == '\0')
    return (0);
  while (str[i] != '\0')
    {
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	i++;
      word++;
      while (str[i] == ' ' || str[i] == '\t')
	i++;
    }
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	word;
  int	i;
  int	j;
  int	curs;

  i = 0;
  j = 0;
  word = count_word(str);
  if ((tab = malloc(sizeof(char*) * (word + 1))) == NULL)
    exit(3);
  tab[word] = NULL;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i] != '\0')
    {
      curs = i;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	i++;
      tab[j] = my_strnncpy(str, curs, i);
      j++;
      while (str[i] == ' ' || str[i] == '\t')
	i++;
    }
  return (tab);
}
