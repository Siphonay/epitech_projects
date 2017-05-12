/*
** minishell1_getenv.c for minishell1 in /home/sam/Rendu/Projets/projet_minishell1/PSU_2015_minishell1/src
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Jan 17 18:33:51 2016 Alexis Viguié
** Last update Mon Jan 18 13:42:58 2016 Alexis Viguié
*/

#include "sam.h"

char		*msh1_getenv(char **ep, char *ename)
{
  unsigned int	counter;

  counter = 0;
  while (ep[counter])
    {
      if (!sam_strncmp(ep[counter], ename, sam_strlen(ename)) &&
	  ep[counter][sam_strlen(ename)] == '=')
	return (&ep[counter][sam_strlen(ename) + 1]);
      counter++;
    }
  return ("");
}
