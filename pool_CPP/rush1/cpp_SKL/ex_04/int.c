/*
** int.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Sat Jan  7 18:08:31 2017 Alexis Viguié
** Last update Sat Jan  7 19:01:50 2017 Alexis Viguié
*/

#include <stdlib.h>
#include "raise.h"
#include "int.h"
#include "new.h"

typedef struct
{
  Class base;
  int	num;
}	IntClass;

static void	Int_ctor(Object *self, va_list *ap)
{
  IntClass	*var;

  var = (IntClass*)self;
  var->num = va_arg(*ap, int);
}

static void	Int_dtor(Object *self)
{
  (void) self;
}

static char const	*Int_to_string_t(Object *self)
{
  char			*ret;
  IntClass		*int_val;

  int_val = (IntClass*)self;
  if (!(ret = malloc(10 * sizeof(char))))
    return (NULL);
  sprintf(ret, "%d", int_val->num);
  return (ret);
}

static Object	*Int_add(Object const *self, Object const *other)
{
  IntClass	*var1;
  IntClass	*var2;
  Object     	*result;
  IntClass	*newResult;

  var1 = (IntClass*)self;
  var2 = (IntClass*)other;
  result = new(Int, 0);
  newResult = (IntClass*)result;
  newResult->num = var1->num + var2->num;
  return (result);
}

static Object	*Int_sub(Object const *self, Object const *other)
{
  IntClass	*var1;
  IntClass	*var2;
  Object     	*result;
  IntClass	*newResult;

  var1 = (IntClass*)self;
  var2 = (IntClass*)other;
  result = new(Int, 0);
  newResult = (IntClass*)result;
  newResult->num = var1->num - var2->num;
  return (result);
}

static Object	*Int_mul(Object const *self, const Object *other)
{
  IntClass	*var1;
  IntClass	*var2;
  Object     	*result;
  IntClass	*newResult;

  var1 = (IntClass*)self;
  var2 = (IntClass*)other;
  result = new(Int, 0);
  newResult = (IntClass*)result;
  newResult->num = var1->num * var2->num;
  return (result);
}

static Object	*Int_div(Object const *self, Object const *other)
{
  IntClass	*var1;
  IntClass	*var2;
  Object     	*result;
  IntClass	*newResult;

  var1 = (IntClass*)self;
  var2 = (IntClass*)other;
  result = new(Int, 0);
  newResult = (IntClass*)result;
  newResult->num = var1->num / var2->num;
  return (result);
}

static bool	Int_eq(Object const *self, Object const *other)
{
  IntClass	*var1;
  IntClass	*var2;

  var1 = (IntClass*)self;
  var2 = (IntClass*)other;
  return (var1->num == var2->num);
}

static bool	Int_gt(Object const *self, Object const *other)
{
  IntClass	*var1;
  IntClass	*var2;

  var1 = (IntClass*)self;
  var2 = (IntClass*)other;
  return (var1->num > var2->num);
}

static bool	Int_lt(Object const *self, Object const *other)
{
  IntClass	*var1;
  IntClass	*var2;

  var1 = (IntClass*)self;
  var2 = (IntClass*)other;
  return (var1->num < var2->num);
}

static IntClass _description = {
  { sizeof(IntClass), "Int", &Int_ctor, &Int_dtor, &Int_to_string_t, &Int_add,
    &Int_sub,
    &Int_mul, &Int_div, &Int_eq, &Int_gt, &Int_lt }, 0 };

Class* Int = (Class*) &_description;
