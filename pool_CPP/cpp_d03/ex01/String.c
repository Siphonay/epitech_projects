/*
** String.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:32:03 2017 Alexis Viguié
** Last update Fri Jan  6 21:02:06 2017 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include "String.h"

static void	assign_s(String *this, String const *str);
static void	assign_c(String *this, char const *s);

static char	*strdup_nullcheck(char const *s)
{
  if (!s)
    return (NULL);
  else
    return (strdup(s));
}

void	StringInit(String *this, char const *s)
{
  this->str = strdup_nullcheck(s);
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
}

void	StringDestroy(String *this)
{
  if (this)
    {
      if (this->str)
	free(this->str);
      this->str = NULL;
    }
}


static void	assign_s(String *this, String const *str)
{
  if (this)
    {
      if (this->str)
	{
	  free(this->str);
	  this->str = NULL;
	}
      this->str = strdup_nullcheck(str->str);
    }
}

static void	assign_c(String *this, char const * s)
{
  if (this)
    {
      if (this->str)
	{
	  free(this->str);
	  this->str = NULL;
	}
      this->str = strdup_nullcheck(s);
    }
}
