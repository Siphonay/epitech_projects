/*
** vertex.c for cpp_SKL
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 07 14:56:03 2017 Alexandre Gaubert
** Last update	Sat Jan 07 17:52:35 2017 Alexandre Gaubert
*/

#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "vertex.h"
#include "raise.h"

typedef struct
{
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(Object* self, va_list *ap)
{
  VertexClass *new;

  new = (VertexClass *)self;
  new->x = va_arg(*ap, int);
  new->y = va_arg(*ap, int);
  new->z = va_arg(*ap, int);
  return (void)self;
}

static void Vertex_dtor(Object* self)
{
  (void)self;
}

static char const	*Vertex_to_string_t(Object* self)
{
  VertexClass	*var;
  int	n1;
  int	n2;
  int	n3;
  int	curs1;
  int	curs2;
  int	curs3;
  int	len;
  char	*str;

  var = (VertexClass*)self;
  n1 = var->x;
  n2 = var->y;
  n3 = var->z;
  curs1 = 1;
  curs2 = 1;
  curs3 = 1;
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
  if (n3 < 0)
    {
      n3 *= -1;
      curs3++;
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
  while (n3 > 9)
    {
      n3 /= 10;
      curs3++;
    }
  len = 15 + curs1 + curs2 + curs3;
  if ((str = malloc(sizeof(char) * len)) == NULL)
    raise("error Malloc");
  snprintf(str, len, "<Vertex (%d, %d, %d)>", var->x, var->y, var->z);
  return (str);
}

static VertexClass _description = {
    { sizeof(VertexClass), "Vertex", &Vertex_ctor, &Vertex_dtor, &Vertex_to_string_t },
    0, 0, 0
};

Class* Vertex = (Class*) &_description;
