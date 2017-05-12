/*
** main.c for infadd in /home/viguie_a/rendu_infinadd/Piscine_C_infinadd
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Mon Oct 19 15:30:10 2015 Alexis Viguié
** Last update Wed Oct 21 01:09:40 2015 Alexis Viguié
*/

#include "libmy.a"

int	main(int ac, char **av)
{
  char	**nums;

  if (affacerr(ac,av))
    return (1);
  affacerr(ac, av);
  my_putstr(addinf(setnumstr(av)));
  return (0);
}
