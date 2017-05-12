/*
** String.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:32:03 2017 Alexis Viguié
** Last update Fri Jan  6 21:02:32 2017 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include "String.h"

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
  this->StringDestroy = &StringDestroy;
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
