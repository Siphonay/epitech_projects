/*
** ecrit-du-texte.c for corewar bootstrap in /home/sam/Rendu/Projets/projet_corewar/CPE_2015_corewar_bootstrap/partie1/etape0
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Thu Feb 25 15:20:08 2016 Alexis Viguié
** Last update Thu Feb 25 15:25:55 2016 Alexis Viguié
*/

#include <stdio.h>

int	main()
{
  FILE	*to_open_file;

  if ((to_open_file = fopen("du-texte.yolo", "w+")) == NULL)
    return (1);
  if ((fprintf(to_open_file, "Hello bambino\n")) < 0)
    return (1);
  if (fclose(to_open_file) == EOF)
    return (1);
  return (0);
}
