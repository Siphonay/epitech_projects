/*
** String.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:32:03 2017 Alexis Viguié
** Last update Fri Jan  6 21:04:14 2017 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include "String.h"

static void	assign_s(String *this, String const *str);
static void	assign_c(String *this, char const *s);
static void	append_s(String *this, String const *ap);
static void	append_c(String *this, char const *aps);
static char	at(String *this, size_t pos);
static void	clear(String *this);

static char	*strdup_nullcheck(char const *s)
{
  if (!s)
    return (NULL);
  else
    return (strdup(s));
}

static char	*strcat_nullcheck(char *dest, char const *src)
{
  char const	*src_copy;

  if (!dest)
    {
      if (!(dest = malloc(sizeof(char))))
	return (NULL);
      dest[0] = '\0';
    }
  if (!src)
    src_copy = "";
  else
    src_copy = src;
  if (!(dest = realloc(dest, (strlen(dest) + strlen(src_copy) + 1) *
		       sizeof(char))))
    return (NULL);
  return (strcat(dest, src_copy));
}

void	StringInit(String *this, char const *s)
{
  this->str = strdup_nullcheck(s);
  this->assign_s = &assign_s;
  this->assign_c = &assign_c;
  this->append_s = &append_s;
  this->append_c = &append_c;
  this->at = &at;
  this->clear = &clear;
}

void	StringDestroy(String *this)
{
  if (this)
    {
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

static void	append_s(String *this, String const *ap)
{
  if (this)
    this->str = strcat_nullcheck(this->str, ap->str);
}


static void	append_c(String *this, char const *aps)
{
  if (this)
    this->str = strcat_nullcheck(this->str, aps);
}

static char	at(String *this, size_t pos)
{
  if (this)
    {
      if (!this->str || pos > strlen(this->str))
	return (-1);
      else
	return (this->str[pos]);
    }
  return (-1);
}

static void	clear(String *this)
{
  if (this)
    {
      if (this->str)
	memset(this->str, 0, strlen(this->str));
    }
}
