/*
** ecrit-un-nombre-int.c for bootstrap corewar in /home/sam/Rendu/Projets/projet_corewar/CPE_2015_corewar_bootstrap/partie1/etape0
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 25 15:29:18 2016 Alexis Viguié
** Last update Thu Feb 25 15:32:00 2016 Alexis Viguié
*/

#include <stdio.h>

int	main()
{
  FILE	*to_open_file;
  int	to_write_int;

  to_write_int = 12345678;
  if ((to_open_file = fopen("nombre-en-int.yolo", "w+")) == NULL)
    return (1);
  if ((fwrite(&to_write_int, sizeof(int), 1, to_open_file)) == 0)
    return (1);
  if (fclose(to_open_file) == EOF)
    return (1);
  return (0);
}
