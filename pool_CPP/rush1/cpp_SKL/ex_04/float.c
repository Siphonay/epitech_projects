/*
** float.c for ex04 in /home/luxey_y/rendu/Piscine_CPP/cpp_SKL/ex_04
** 
** Made by Yann Luxey
** Login   <luxey_y@epitech.net>
** 
** Started on  Sat Jan  7 17:25:10 2017 Yann Luxey
** Last update Sat Jan  7 19:13:51 2017 Alexis Viguié
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <float.h>
#include "raise.h"
#include "float.h"
#include "new.h"

typedef struct
{
  Class base;
  float x;
} FloatClass;

static void Float_ctor(Object* self, va_list *ap)
{
  FloatClass    *var;

  var = (FloatClass*)self;
  var->x = va_arg(*ap, double);
}

static void Float_dtor(Object* self)
{
  (void) self;
}

static char const       *Float_to_string_t(Object* self)
{
  FloatClass    *var;

  char  *str;

  var = (FloatClass*)self;

  if (!(str = malloc(sizeof(char) * 512)))
    raise("error Malloc");
  sprintf(str, "<Float %f>", var->x);
  return (str);
}

static Object	*Float_add(Object const *self, Object const *other)
{
  FloatClass	*var1;
  FloatClass	*var2;
  Object     	*result;
  FloatClass	*newResult;

  var1 = (FloatClass*)self;
  var2 = (FloatClass*)other;
  result = new(Float, 0);
  newResult = (FloatClass*)result;
  newResult->x = var1->x + var2->x;
  return (result);
}

static Object	*Float_sub(Object const *self, Object const *other)
{
  FloatClass	*var1;
  FloatClass	*var2;
  Object     	*result;
  FloatClass	*newResult;

  var1 = (FloatClass*)self;
  var2 = (FloatClass*)other;
  result = new(Float, 0);
  newResult = (FloatClass*)result;
  newResult->x = var1->x - var2->x;
  return (result);
}

static Object	*Float_mul(Object const *self, const Object *other)
{
  FloatClass	*var1;
  FloatClass	*var2;
  Object     	*result;
  FloatClass	*newResult;

  var1 = (FloatClass*)self;
  var2 = (FloatClass*)other;
  result = new(Float, 0);
  newResult = (FloatClass*)result;
  newResult->x = var1->x * var2->x;
  return (result);
}

static Object	*Float_div(Object const *self, Object const *other)
{
  FloatClass	*var1;
  FloatClass	*var2;
  Object     	*result;
  FloatClass	*newResult;

  var1 = (FloatClass*)self;
  var2 = (FloatClass*)other;
  result = new(Float, 0);
  newResult = (FloatClass*)result;
  newResult->x = var1->x / var2->x;
  return (result);
}

static bool	Float_eq(Object const *self, Object const *other)
{
  FloatClass	*var1;
  FloatClass	*var2;

  var1 = (FloatClass*)self;
  var2 = (FloatClass*)other;
  return (var1->x == var2->x);
}

static bool	Float_gt(Object const *self, Object const *other)
{
  FloatClass	*var1;
  FloatClass	*var2;

  var1 = (FloatClass*)self;
  var2 = (FloatClass*)other;
  return (var1->x > var2->x);
}

static bool	Float_lt(Object const *self, Object const *other)
{
  FloatClass	*var1;
  FloatClass	*var2;

  var1 = (FloatClass*)self;
  var2 = (FloatClass*)other;
  return (var1->x < var2->x);
}

static FloatClass _description = {
  { sizeof(FloatClass), "Float", &Float_ctor, &Float_dtor, &Float_to_string_t, &Float_add,
    &Float_sub,
    &Float_mul, &Float_div, &Float_eq, &Float_gt, &Float_lt }, 0 };

Class* Float = (Class*) &_description;


