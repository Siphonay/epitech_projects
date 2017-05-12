/*
** String.h for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Fri Jan  6 09:55:43 2017 Alexis Viguié
** Last update Fri Jan  6 20:57:26 2017 Alexis Viguié
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct	String
{
  char		*str;
}		String;

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);

#endif /* !STRING_H_ */
