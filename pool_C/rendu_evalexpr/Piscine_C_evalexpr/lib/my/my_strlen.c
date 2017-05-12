/*
** my_strlen.c for  in /home/viguie_a/rendu_j04
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Thu Oct  1 17:15:38 2015 Alexis Viguié
** Last update Tue Oct  6 14:03:51 2015 Alexis Viguié
*/

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (*str != '\0')
    {
      str++;
      counter++;
    }
  return (counter);
}
