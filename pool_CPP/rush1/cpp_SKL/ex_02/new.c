/*
** new.c for rush in /home/luxey_y/rendu/Piscine_CPP/cpp_SKL/ex_01
**
** Made by Yann Luxey
** Login   <luxey_y@epitech.net>
**
** Started on  Sat Jan  7 09:41:24 2017 Yann Luxey
** Last update	Sat Jan 07 17:18:09 2017 Alexandre Gaubert
*/

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "new.h"
#include "point.h"
#include "raise.h"

void	*new(Class *class, ...)
{
  Class	*elem;
  void	*new;
  va_list	ap;

  new = NULL;
  if (class != NULL)
    {
      if ((new = malloc(class->__size__)) == NULL)
	raise("Error malloc");
      if ((new = memcpy(new, class, class->__size__)) == NULL)
	raise("Error memcpy");
      elem = new;
      va_start(ap, class);
      if (elem->__init__ != NULL)
	elem->__init__(new, &ap);
      va_end(ap);
    }
  return (new);
}

void	*va_new(Class *class, va_list *ap)
{
  Class	*elem;
  void	*new;

  new = NULL;
  if (class != NULL)
    {
      if ((new = malloc(class->__size__)) == NULL)
	raise("Error malloc");
      if ((new = memcpy(new, class, class->__size__)) == NULL)
	raise("Error memcpy");
      elem = new;
      if (elem->__init__ != NULL)
	elem->__init__(new, ap);
    }
  return (new);
}

void	delete(Object* ptr)
{
  Class	*elem;

  if (ptr != NULL)
    {
      elem = ptr;
      if (elem->__del__ != NULL)
	elem->__del__(ptr);
      free(ptr);
    }
}
