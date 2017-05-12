/*
** mylist.h for mylist in /home/viguie_a/rendu_j11/Piscine_C_J11
** 
** Made by Alexis Viguié
** Login   <viguie_a@epitech.net>
** 
** Started on  Mon Oct 12 11:44:42 2015 Alexis Viguié
** Last update Mon Oct 12 15:38:19 2015 Alexis Viguié
*/

#ifndef LIST_DEC_
# define LIST_DEC_
typedef	struct s_list
{
  void *data;
  struct s_list *next;
} t_list;
#endif
