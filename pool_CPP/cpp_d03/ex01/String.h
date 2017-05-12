/*
** String.h for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:55:43 2017 Alexis Viguié
** Last update Fri Jan  6 21:02:17 2017 Alexis Viguié
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct	String
{
  char		*str;

  void		(*assign_s)(struct String *this, struct String const *str);
  void		(*assign_c)(struct String *this, char const *s);
}		String;

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !STRING_H_ */
