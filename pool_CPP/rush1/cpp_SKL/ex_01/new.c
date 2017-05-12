/*
** new.c for rush in /home/luxey_y/rendu/Piscine_CPP/cpp_SKL/ex_01
** 
** Made by Yann Luxey
** Login   <luxey_y@epitech.net>
** 
** Started on  Sat Jan  7 09:41:24 2017 Yann Luxey
** Last update Sat Jan  7 11:39:40 2017 Yann Luxey
*/

#include <string.h>
#include <stdlib.h>
#include "new.h"
#include "point.h"
#include "raise.h"

void	*new(Class *class)
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
	elem->__init__(new);
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
