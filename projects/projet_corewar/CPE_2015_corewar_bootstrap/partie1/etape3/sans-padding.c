/*
** sans-padding.c for bootstrap corewar in /home/sam/Rendu/Projets/projet_corewar/CPE_2015_corewar_bootstrap/partie1/etape0
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 25 16:12:20 2016 Alexis Viguié
** Last update Thu Feb 25 16:17:38 2016 Alexis Viguié
*/

#include <stdio.h>

int	main()
{
  FILE	*to_open_file;
  int	to_write_int;
  char	to_write_char;

  to_write_int = 192873;
  to_write_char = 'k';
  if (!(to_open_file = fopen("plusieurs-variables.yolo", "w+")))
    return (1);
  if (!(fwrite(&to_write_int, sizeof(int), 1, to_open_file)) &&
      !(fwrite(&to_write_char, sizeof(char), 1, to_open_file)) &&
      !(fwrite("Le Corewar, c'est swag!!", sizeof(char), 40, to_open_file)))
    return (1);
  if (fclose(to_open_file) == EOF)
    return (1);
  return (0);
}
