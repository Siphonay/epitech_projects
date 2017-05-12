/*
** func_ptr.h for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d02m/ex03
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Thu Jan  5 15:49:38 2017 Alexis Viguié
** Last update Thu Jan  5 16:16:03 2017 Alexis Viguié
*/

#ifndef FUNC_PTR_H_
# define FUNC_PTR_H_

# include "func_ptr_enum.h"

void		print_normal(char *str);
void		print_reverse(char *str);
void		print_upper(char *str);
void		print_42(char *str);
void		do_action(t_action action, char *str);

typedef void	(*print_func)(char *);

#endif /* !FUNC_PTR_H_ */
