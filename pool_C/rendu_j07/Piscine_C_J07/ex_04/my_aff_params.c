/*
** my_aff_params.c for my aff params in /home/viguie_a/rendu_j07/Piscine_C_J07/ex_04
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Tue Oct  6 21:55:04 2015 Alexis Viguié
** Last update Wed Oct  7 13:56:01 2015 Alexis Viguié
*/

void	main(int argc, char **argv)
{
  int	counter;

  counter = 0;
  while (counter < argc)
    {
      my_putstr(argv[i]);
      counter++;
      if (counter < argc)
	my_putchar(' ');
    }
}
