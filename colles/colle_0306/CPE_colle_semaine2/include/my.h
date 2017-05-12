/*
** my.h for my.h in /home/joly_r/rendu/Colles/Colle2/Colle2/include
**
** Made by joly_r
** Login   <joly_r@epitech.net>
**
** Started on  Tue May  3 14:32:04 2016 joly_r
** Last update Tue May  3 17:36:39 2016 Alexis Viguié
*/

#ifndef MY_H_
#define MY_H_

# include <unistd.h>
# include <stdbool.h>

size_t  my_strlen(const char *str);
int     my_get_nbr(const char *str);
bool    my_strcmp(const char *s1, const char *s2);
void    my_putstr(const char *str);
void    my_putstr_err(const char *str);
void	my_putchar(char a);

void	print_board(char **board);
void	free_tab(char **tab);
void	fill_line(char **board, int width, int i);



#endif /* MY_H_ */
