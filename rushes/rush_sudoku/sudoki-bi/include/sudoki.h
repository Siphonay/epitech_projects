/*
** sudoki.h for sudoki bi in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Sat Feb 27 10:18:18 2016 Alexis Viguié
** Last update Sat Feb 27 14:52:13 2016 Alexis Viguié
*/

#ifndef SUDOKI_H_
# define SUDOKI_H_

unsigned char	***sudoki_parse();

unsigned char	**sudoki_algo(unsigned char **sudoki_grid);

void	sudoki_disp(unsigned char ***sudoki_tabke);

void	sudoki_free(unsigned char ***sudoki_table);

#endif /* !SUDOKI_H_ */
