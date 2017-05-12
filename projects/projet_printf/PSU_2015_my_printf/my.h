/*
** my.h for my printf in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Nov 13 16:04:15 2015 Alexis Viguié
** Last update Mon Nov 16 23:35:52 2015 Alexis Viguié
*/

#ifndef MY_PRINTF
# define MY_PRINTF
int	my_printf(char *format, ...);
int	my_strlen(char *str);
void	my_putstr(char *str);
void	my_putstr_noimp(char *str);
void	my_putarg(int arg, char argtype);
void	my_put_base_str(int nb, char *base);
void	my_putptr(void *ptr);
char	*my_int_to_base_str(int nb, char *base);
#endif
#ifndef HEXA_UPPERCASE
# define HEXA_UPPERCASE "0123456789ABCDEF"
#endif
#ifndef HEXA_LOWERCASE
# define HEXA_LOWERCASE "0123456789abcdef"
#endif
#ifndef DECIMAL
# define DECIMAL "0123456789"
#endif
#ifndef OCTAL
# define OCTAL "01234567"
#endif
#ifndef BINARY
# define BINARY "01"
#endif
