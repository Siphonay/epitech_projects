/*
** point.c for ex02 in /home/luxey_y/rendu/Piscine_CPP/cpp_SKL/ex_02
**
** Made by Yann Luxey
** Login   <luxey_y@epitech.net>
**
** Started on  Sat Jan  7 12:44:03 2017 Yann Luxey
** Last update	Sat Jan 07 16:58:46 2017 Alexandre Gaubert
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "raise.h"
#include "point.h"

typedef struct
{
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(Object* self, va_list *ap)
{
  PointClass	*var;

  var = (PointClass*)self;
  var->x = va_arg(*ap, int);
  var->y = va_arg(*ap, int);
}

static void Point_dtor(Object* self)
{
    (void) self;
}

static char const	*Point_to_string_t(Object* self)
{
  PointClass	*var;
  int	n1;
  int	n2;
  int	curs1;
  int	curs2;
  int	len;
  char	*str;

  var = (PointClass*)self;
  n1 = var->x;
  n2 = var->y;
  curs1 = 1;
  curs2 = 1;
  if (n1 < 0)
    {
      n1 *= -1;
      curs1++;
    }
  if (n2 < 0)
    {
      n2 *= -1;
      curs2++;
    }
  while (n1 > 9)
    {
      n1 /= 10;
      curs1++;
    }
  while (n2 > 9)
    {
      n2 /= 10;
      curs2++;
    }
  len = 13 + curs1 + curs2;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    raise("error Malloc");
    // printf("%d\n", var->x);
  snprintf(str, len, "<Point (%d, %d)>", var->x, var->y);
  return (str);
}

static PointClass _description = {
  { sizeof(PointClass), "Point", &Point_ctor, &Point_dtor, &Point_to_string_t },
    0, 0
};

Class* Point = (Class*) &_description;
