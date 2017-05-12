/*
** errorhandle.c for infadd in /home/viguie_a/rendu_infinadd/Piscine_C_infinadd
**
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
**
** Started on  Mon Oct 19 21:33:39 2015 Alexis Viguié
** Last update Wed Oct 21 01:10:39 2015 Alexis Viguié
*/

int	affacerr(int ac, char **av)
{
  char	*errmess;
  int	binnamelen;

  binnamelen = my_strlen(av[0]);
  if (ac != 3)
    {
      write(2, av[0], binnamelen);
      write(2, ": num1 num2\n", 12);
      return (1);
    }
  else
    return (0);
}
