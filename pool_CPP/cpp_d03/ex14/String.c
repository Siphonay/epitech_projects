/*
** String.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:32:03 2017 Alexis Viguié
** Last update Sat Jan  7 09:39:27 2017 Alexis Viguié
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "String.h"

static void		assign_s(String *this, String const *str);
static void		assign_c(String *this, char const *s);
static void		append_s(String *this, String const *ap);
static void		append_c(String *this, char const *aps);
static char		at(String *this, size_t pos);
static void		clear(String *this);
static int		size(String *this);
static int		compare_s(String *this, String const *str);
static int		compare_c(String *this, char const *str);
static size_t		copy(String *this, char *s, size_t n, size_t pos);
static char const	*c_str(String *this);
static int		empty(String *this);
static int		find_s(String *this, String const *str, size_t pos);
static int		find_c(String *this, char const *str, size_t pos);
static void		insert_c(String *this, size_t pos, char const *str);
static void		insert_s(String *this, size_t pos, String const *str);
static int		to_int(String *this);
static void		aff(String *this);

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
  this->c_str = &c_str;
  this->empty = &empty;
  this->find_s = &find_s;
  this->find_c = &find_c;
  this->insert_c = &insert_c;
  this->insert_s = &insert_s;
  this->to_int = &to_int;
  this->aff = &aff;
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
  return (-1);
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
  return (0);
}

static char const	*c_str(String *this)
{
  if (this)
    return (this->str);
  return (NULL);
}

static int	empty(String *this)
{
  if (this)
    {
      if (!this->str || !this->str[0])
	return (1);
      else
	return (-1);
    }
  return (1);
}

static int	find_s(String *this, String const *str, size_t pos)
{
  unsigned int	counter;

  if (this)
    {
      if (pos > strlen(this->str))
	return (-1);
      while (strlen(&this->str[pos]) >= strlen(str->str))
	{
	  counter = 0;
	  while (this->str[pos + counter] == str->str[counter] && str->str[counter])
	    counter++;
	  if (!str->str[counter])
	    return (pos);
	  pos++;
	}
      return (-1);
    }
  return (-1);
}

static int	find_c(String *this, char const *str, size_t pos)
{
  unsigned int	counter;

  if (this)
    {
      if (pos > strlen(this->str))
	return (-1);
      while (strlen(&this->str[pos]) >= strlen(str))
	{
	  counter = 0;
	  while (this->str[pos + counter] == str[counter] && str[counter])
	    counter++;
	  if (!str[counter])
	    return (pos);
	  pos++;
	}
      return (-1);
    }
  return (-1);
}


static void	insert_c(String *this, size_t pos, char const *str)
{
  String	temp_end;

  if (this)
    {
      if (pos >= strlen(this->str))
	this->append_c(this, str);
      else
	{
	  StringInit(&temp_end, &this->str[pos + 1]);
	  this->str = realloc(this->str, (pos + 1) * sizeof(char));
	  this->str[pos] = '\0';
	  this->append_c(this, str);
	  this->append_s(this, &temp_end);
	  StringDestroy(&temp_end);
	}
    }
}

static void	insert_s(String *this, size_t pos, String const *str)
{
  String	temp_end;

  if (this)
    {
      if (pos >= strlen(this->str))
	this->append_s(this, str);
      else
	{
	  StringInit(&temp_end, &this->str[pos + 1]);
	  this->str = realloc(this->str, (pos + 1) * sizeof(char));
	  this->str[pos] = '\0';
	  this->append_s(this, str);
	  this->append_s(this, &temp_end);
	  StringDestroy(&temp_end);
	}
    }
}

static int	to_int(String *this)
{
  if (this)
    return (atoi(this->str));
  else
    return (0);
}

static void	aff(String *this)
{
  if (this && this->str)
    write(1, this->str, strlen(this->str));
}
