/*
** remove_trailing_semicolon.c for rush mai in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat May 14 17:35:17 2016 Alexis Viguié
** Last update Sat May 14 17:36:16 2016 Alexis Viguié
*/

char	*remove_trailing_semicolon(char *name)
{
  int	counter;

  counter = 0;
  while (name[counter])
    counter++;
  name[counter - 1] = '\0';
  return (name);
}
