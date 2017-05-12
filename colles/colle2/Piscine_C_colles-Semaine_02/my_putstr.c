/*
** my_putstr.c for putstr colle 2 in /home/viguie_a/rendu_colle2
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Sat Oct 10 16:17:38 2015 Alexis Viguié
** Last update Sat Oct 10 16:23:38 2015 Alexis Viguié
*/

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str++;
    }
}
