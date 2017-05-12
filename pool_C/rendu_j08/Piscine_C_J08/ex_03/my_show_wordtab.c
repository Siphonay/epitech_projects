/*
** my_show_wordtab.c for my show wordtab in /home/viguie_a/rendu_j08/Piscine_C_J08/ex_03
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Wed Oct  7 16:21:47 2015 Alexis Viguié
** Last update Wed Oct  7 16:40:54 2015 Alexis Viguié
*/

int	my_show_wordtab(char **tab)
{
  int	counter;
  int	counter2;

  counter = 0;
  while (tab[counter] != 0)
    {
      counter2 = 0;
      while (tab[counter][counter2] != '\0')
	{
	  my_putchar(tab[counter][counter2]);
	  counter2++;
	}
      my_putchar('\n');
      counter++;
    }
  return (0);
}
