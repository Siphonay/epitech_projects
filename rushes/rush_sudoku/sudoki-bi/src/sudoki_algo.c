/*
** sudoki_algo.c for sudoki_algo in /home/laronc_a/semestre_2/rush/sudoki-bi
**
** Made by Alexandre LARONCE
** Login   <laronc_a@epitech.net>
**
** Started on  Sat Feb 27 10:21:32 2016 Alexandre LARONCE
** Last update Sat Feb 27 15:19:33 2016 Alexis Viguié
*/

#include <stdlib.h>

char	*check_line(unsigned char **tab, char *list, int h)
{
  int	i;

  i = 0;
  while (i != 9)
    {
      if (tab[h][i] > '0'&& tab[h][i] <= '9')
	list[tab[h][i] - 49] = tab[h][i];
      i++;
    }
  return (list);
}

char	*check_collumn(unsigned char **tab, char *list, int l)
{
  int	i;

  i = 0;
  while (i != 9)
    {
      if (tab[i][l] > '0'&& tab[i][l] <= '9')
	list[tab[i][l] - 49] = tab[i][l];
      i++;
    }
  return (list);
}

char	*check_square_two(unsigned char **tab, char *list, int h, int l)
{
  int	h_max;
  int	l_max;

  h_max = h + 3;
  l_max = l + 3;
  while (h != h_max)
    {
      while (l != l_max)
	{
	  if (tab[h][l] > '0' && tab[h][l] <= '9')
	    list[tab[h][l] - 49] = tab[h][l];
	  l++;
	}
      l = l - 2;
      h++;
    }
  return (list);
}

char	*check_square_one(unsigned char **tab, char *list, int h, int l)
{
  int	i;
  int	j;
  int	test;

  test = (h % 3);
  if (test == 1)
    i = test;
  else if (test == 2)
    i = test - 1;
  else
    i = test - 2;
  test = (l % 3);
  if (test == 1)
    j = test;
  else if (test == 2)
    j = test - 1;
  else
    j = test - 2;
  list = check_square_two(tab, list, i, j);
  return (list);
}

char	check_list(char *list)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  while (list[i] != '\0')
    {
      if (list[i] == 'x')
	nb++;
      i++;
    }
  if (nb == 1)
    {
      i = 0;
      while (list[i] != 'x')
	i++;
      return (i + 1);
    }
  else
    return ('x');
}

unsigned char	**algo_core_system(unsigned char **tab, int h, int l)
{
  int	i;
  char	*list;
  char	new;

  i = 0;
  new = 'x';
  if ((list = malloc(10 * sizeof (char))) == NULL)
    exit(-1);
  list[9] = '\0';
  while (list[i] != '\0')
    {
      list[i] = 'x';
      i++;
    }
  list = check_line(tab, list, h);
  list = check_collumn(tab, list, l);
  list = check_square_one(tab, list, h, l);
  new = check_list(list);
  if (new != 'x')
    tab[h][l] = new;
  free(list);
  return (tab);
}

unsigned char	**sudoki_algo(unsigned char **tab)
{
  int	h;
  int	l;

  h = 0;
  l = 0;
  while (h != 9)
    {
      while (l != 9)
	{
	  if (tab[h][l] == '0')
	    tab = algo_core_system(tab, h, l);
	  l++;
	}
      l = 0;
      h++;
    }
  check_complet(tab);
}


void	check_complet(unsigned char **tab)
{
  int		h;
  int		l;
  int		bool;

  bool = 0;
  h = 0;
  l = 0;
  while (h != 9)
    {
      while (l != 9)
	{
	  if (tab[h][l] < '1' || tab[h][l] > '9')
	    bool++;
	  l++;
	}
      l = 0;
      h++;
    }
  if (bool != 0)
    tab = sudoki_algo(tab);
}
