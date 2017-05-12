/*
** type_detection.c for rush mai in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat May 14 13:55:41 2016 Alexis Viguié
** Last update Sat May 14 16:10:20 2016 Alexis Viguié
*/

#include <string.h>
#include "marvin.h"

char	*detect_long(char **argtab)
{
  if (!strcmp(argtab[0], NAME_LONG))
    return (VAR_LONGLONG);
  else if (!strcmp(argtab[0], NAME_DOUBLE))
    return (VAR_LONGDOUBLE);
  else
    return (VAR_LONG);
}

char	*detect_ulong(char **argtab)
{
  if (!strcmp(argtab[0], NAME_LONG))
    return (VAR_ULONGLONG);
  else
    return (VAR_ULONG);
}

char	*detect_unsigned(char **argtab)
{
  if (!strcmp(argtab[0], NAME_CHAR))
    return (VAR_UCHAR);
  else if (!strcmp(argtab[0], NAME_SHORT))
    return (VAR_USHORT);
  else if (!strcmp(argtab[0], NAME_INT))
    return (VAR_UINT);
  else if (marvin_tablen(argtab) > 2 &&
      !strcmp(argtab[0], NAME_LONG))
    return (detect_ulong(&argtab[1]));
  else
    return (SYNTAX_ERROR);
}

char	*type_detection(char **argtab)
{
  if (!strcmp(argtab[0], NAME_UNSIGNED))
    return (detect_unsigned(&argtab[1]));
  else if (!strcmp(argtab[0], NAME_LONG))
    return (detect_long(&argtab[1]));
  else if (!strcmp(argtab[0], NAME_CHAR))
    return (VAR_CHAR);
  else if (!strcmp(argtab[0], NAME_SHORT))
    return (VAR_SHORT);
  else if (!strcmp(argtab[0], NAME_INT))
    return (VAR_INT);
  else if (!strcmp(argtab[0], NAME_FLOAT))
    return (VAR_FLOAT);
  else if (!strcmp(argtab[0], NAME_DOUBLE))
    return (VAR_DOUBLE);
  else
    return (argtab[0]);
}
