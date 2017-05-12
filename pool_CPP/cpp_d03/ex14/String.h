/*
** String.h for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:55:43 2017 Alexis Viguié
** Last update Sat Jan  7 09:37:12 2017 Alexis Viguié
*/

#ifndef STRING_H_
# define STRING_H_

# include <stdlib.h>

typedef struct	String
{
  char		*str;

  void		(*assign_s)(struct String *this, struct String const *str);
  void		(*assign_c)(struct String *this, char const *s);
  void		(*append_s)(struct String *this, struct String const *ap);
  void		(*append_c)(struct String *this, char const *aps);
  char		(*at)(struct String *this, size_t pos);
  void		(*clear)(struct String *this);
  int		(*size)(struct String *this);
  int		(*compare_s)(struct String *this, struct String const *str);
  int		(*compare_c)(struct String *this, char const *str);
  size_t	(*copy)(struct String *this, char *s, size_t n, size_t pos);
  char const	*(*c_str)(struct String *this);
  int		(*empty)(struct String *this);
  int		(*find_s)(struct String *this, struct String const *str,
			  size_t pos);
  int		(*find_c)(struct String *this, char const *str, size_t pos);
  void		(*insert_c)(struct String *this, size_t pos, char const *str);
  void		(*insert_s)(struct String *this, size_t pos,
			    struct String const *str);
  int		(*to_int)(struct String *this);
  void		(*aff)(struct String *this);
}		String;

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !STRING_H_ */
