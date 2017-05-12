/*
** strtowordtab.c for psu
**
** Made by	pedron_s
** Login	pedron_s
**
** Started on	Sat May 14 01:51:59 2016 pedron_s
** Last update	Sat Jun 04 23:14:05 2016 pedron_s
*/

#include <stdlib.h>
#include <string.h>

char    *my_mem_set2(char *str, int size)
{
  int   i;

  i = 0;
  while (i < size)
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}

int     my_count_line(char *str, char *def)
{
  int   i;
  int	j;
  int   nb;

  i = 0;
  j = 0;
  nb = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      j = 0;
      while (def[j] != '\0')
	{
	  if (str[i] == def[j])
	      nb++;
	  j++;
	}
      i++;
    }
  return (nb);
}

char	*my_opvals(char *tab, char *str, char def, int nb)
{
  if ((tab = malloc(sizeof(char) * (strlen(str) + 2))) == NULL)
    exit(32);
  my_mem_set2(tab, strlen(str) + 1);
  if (nb == 1)
    tab[0] = def;
  return (tab);
}

char	**my_malloc(int nb_line)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (nb_line + 1))) == NULL)
    exit(32);
  while (i < nb_line + 1)
    {
      tab[i] = NULL;
      i++;
    }
  return (tab);
}

char    **my_str_to_wordtab(char *str, char *def, int i, int k)
{
  int   j;
  int	m;
  int   nb_line;
  char  **tab;

  nb_line = my_count_line(str, def) + 1, tab = my_malloc(nb_line);
  while (i < nb_line)
    {
      j = m = 0, tab[i] = my_opvals(tab[i], str, 0, 0);
      while (str[k] != def[m] && str[k] != '\0')
	{
	  m = 0;
	  while (def[m] != '\0' && str[k] != def[m])
	    m++;
	  if (def[m] != '\0')
	    break;
	  ((def[m] == '\0') ? tab[i][j++] = str[k++] : 1);
	}
      (tab[i][0] != '\0') ? i++ : 0;
      if (def[m] != ' ' && def[m] != '\0')
	tab[i] = my_opvals(tab[i], str, def[m], 1), i++;
      (str[k] != '\0') ? (k += 1) : i++;
      (i <= nb_line) ? tab[i] = NULL : 0;
    }
  return (tab);
}
