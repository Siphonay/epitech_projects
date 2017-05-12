/*
** my.h for myh in /home/zaza/rendu/PSU_2015_minishell2/include/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 20:27:18 2016 thibault derbre
** Last update Tue Apr  5 14:03:32 2016 thibault derbre
*/

#ifndef MY_H
# define MY_H

#include <stdarg.h>
#include <unistd.h>

int	display(int i, const char *format, va_list arg);
int	display2(int i, const char *format, va_list arg);
int	my_printf(const char *format, ...);
int	my_put_nbr(int nb);
int	my_put_nbr_base(char *base, int nb);
unsigned int	my_put_nbr_un(unsigned int nb);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
ssize_t write(int fd, const void *buf, size_t count);
int	my_putstr_cc(char *str);
void	enc_plus_cc(char *str, int *i);
int	fonction(int *i, int *a, const char *format, va_list arg);
int	my_put_nbr_base_cc(char *base, long nb);

#endif /* MY_H */
