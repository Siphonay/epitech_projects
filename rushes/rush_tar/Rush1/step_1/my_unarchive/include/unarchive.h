/*
** unarchive.h for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 19:48:21 2016 Alexis Viguié
** Last update Sat Jan  9 19:59:49 2016 Alexis Viguié
*/

#ifndef UNARCHIVE_H_
# define UNARCHIVE_H_

#define MAGIC_SIZE 4
#define MAGIC_NUMBER "tek\0"

#include <stdio.h>

void	extract_arc(FILE *archive);

#endif /* !UNARCHIVE_H_ */
