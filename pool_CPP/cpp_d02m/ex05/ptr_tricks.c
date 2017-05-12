/*
** ptr_tricks.c for Project-Master in /home/sam
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 17:54:34 2017 Alexis Viguié
** Last update Thu Jan  5 18:24:56 2017 Alexis Viguié
*/

#include <stddef.h>
#include "ptr_tricks.h"

int	get_array_nb_elem(int *ptr1, int *ptr2)
{
  return (ptr2 - ptr1);
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
  return ((t_whatever *)((char*)(member_ptr) - offsetof(t_whatever, member)));
}
