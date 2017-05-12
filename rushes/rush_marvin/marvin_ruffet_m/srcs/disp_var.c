/*
** disp_var.c for rush mai in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat May 14 16:50:57 2016 Alexis Viguié
** Last update Sat May 14 17:42:17 2016 Alexis Viguié
*/

#include <stdio.h>
#include <string.h>
#include "marvin.h"

void	disp_var_size4(char **argtab, char *var_type)
{
  if (marvin_tablen(argtab) != 4)
    printf(SYNTAX_ERROR);
  else
    {
      printf("%s %s ", DEF, ART_VAR);
      printf(DEF_VAR, var_type, remove_trailing_semicolon(argtab[3]));
    }
}

void	disp_var_size3(char **argtab, char *var_type)
{
  if (marvin_tablen(argtab) != 3)
    printf(SYNTAX_ERROR);
  else
    {
      printf("%s %s ", DEF, ART_VAR);
      printf(DEF_VAR, var_type, remove_trailing_semicolon(argtab[2]));
    }
}

void	disp_var_size2(char **argtab, char *var_type)
{
  if (marvin_tablen(argtab) != 2)
    printf(SYNTAX_ERROR);
  else
    {
      printf("%s %s ", DEF, ART_VAR);
      printf(DEF_VAR, var_type, remove_trailing_semicolon(argtab[1]));
    }
}

void	disp_var(char **argtab)
{
  char	*var_type;

  var_type = type_detection(argtab);
  if (!strcmp(var_type, VAR_UCHAR) ||
      !strcmp(var_type, VAR_USHORT) ||
      !strcmp(var_type, VAR_UINT) ||
      !strcmp(var_type, VAR_ULONG) ||
      !strcmp(var_type, VAR_LONGDOUBLE))
    disp_var_size3(argtab, var_type);
  else if (!strcmp(var_type, VAR_ULONGLONG))
    disp_var_size4(argtab, var_type);
  else if (!strcmp(var_type, SYNTAX_ERROR))
    printf(SYNTAX_ERROR);
  else
    disp_var_size2(argtab, var_type);
  printf("\n");
}
