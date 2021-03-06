/*
** String.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:32:03 2017 Alexis Viguié
** Last update Fri Jan  6 21:12:04 2017 Alexis Viguié
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
static int	size(String *this);
static int	compare_s(String *this, String const *str);
static int	compare_c(String *this, char const *str);
static size_t	copy(String *this, char *s, size_t n, size_t pos);

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
  this->size = &size;
  this->compare_s = &compare_s;
  this->compare_c = &compare_c;
  this->copy = &copy;
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

static int	size(String *this)
{
  if (this)
    {
      if (this->str)
	return (strlen(this->str));
      else
	return (-1);
    }
}

static int	compare_s(String *this, String const *str)
{
  char const   	*this_copy;
  char const   	*str_copy;

  if (this)
    {
      if (!this->str)
	this_copy = "";
      else
	this_copy = this->str;
      if (!str->str)
	str_copy = "";
      else
	str_copy = str->str;
      return (strcmp(this_copy, str_copy));
    }
  return (0);
}

static int	compare_c(String *this, char const *str)
{
  char const	*this_copy;
  char const	*str_copy;

  if (this)
    {
      if (!this->str)
	this_copy = "";
      else
	this_copy = this->str;
      if (!str)
	str_copy = "";
      else
	str_copy = str;
      return (strcmp(this_copy, str_copy));
    }
    return (0);
}

static size_t	copy(String *this, char *s, size_t n, size_t pos)
{
  unsigned int 	counter;

  if (this)
    {
      if (pos > strlen(s))
	return (0);
      counter = 0;
      while (counter < n && this->str[pos + counter])
	{
	  s[counter] = this->str[pos + counter];
	  counter++;
	}
      return (counter);
    }
  return (-1);
}
