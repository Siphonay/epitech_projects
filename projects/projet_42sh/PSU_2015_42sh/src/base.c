/*
** base.c for base in /home/zaza/rendu/PSU_2015_42sh/src/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Thu May 19 14:03:07 2016 thibault derbre
** Last update Thu May 19 14:46:36 2016 Alexis Viguié
*/

#include <sys/types.h>

size_t		wordtablen(char **wordtab)
{
  size_t		counter;

  counter = 0;
  while (wordtab[counter])
    counter++;
  return (counter);
}
