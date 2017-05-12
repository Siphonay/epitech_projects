/*
** avec-padding.c for bootstrap corewar in /home/sam/Rendu/Projets/projet_corewar/CPE_2015_corewar_bootstrap/partie1/etape0
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 25 16:18:48 2016 Alexis Viguié
** Last update Tue Mar 22 09:39:40 2016 Alexis Viguié
*/

#include <stdio.h>
#include <string.h>
#include "avec_padding.h"

int		main()
{
  FILE		*to_open_file;
  t_towrite	towrite_struct;

  towrite_struct.towrite_int = 19873;
  towrite_struct.towrite_char = 'k';
  strncpy(towrite_struct.towrite_str, "Le Corewar, c'est swag!!", 24);
  if (!(to_open_file = fopen("une-structure.yolo", "w+")))
    return (1);
  if (!(fwrite(&towrite_struct, sizeof(t_towrite), 1, to_open_file)))
    return (1);
  if (fclose(to_open_file) == EOF)
    return (1);
  return (0);
}
