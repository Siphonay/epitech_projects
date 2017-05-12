/*
** strcmp_functions.c for strcmp_functions in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 20:16:38 2016 thibault derbre
** Last update Mon Apr 11 19:23:21 2016 thibault derbre
*/

#include "get_next_line.h"
#include "mysh.h"

int	my_strcmp_env(char *str, char *buff)
{
  int	i;

  i = 0;
  while (str[i] != '=')
    {
      if (str[i] == buff[i])
	i++;
      else
	return (0);
      if (str[i] == '\0')
	return (0);
  }
  if (buff[i] == '=')
    {
      return (1);
    }
  return (0);
}

int     my_strcmp(char *s1, char *s2)
{
  while (*s1 == *s2++)
    {
      if (*s1++ == '\0')
	return (0);
    }
  return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

int	my_strcmp_setenv(char *str, char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '=')
    {
      if (buff[i] != str[i])
	return (0);
      i++;
    }
  return (1);
}

void	my_show_list(t_list *lex)
{
  while (lex->next != NULL)
    {
      my_putstr(lex->cmd);
      my_putchar('\n');
      lex = lex->next;
    }
  my_putstr(lex->cmd);
  my_putchar('\n');
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n + 1)
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  return (0);
}
