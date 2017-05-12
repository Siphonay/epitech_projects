/*
** sam.h for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec  4 14:41:28 2015 Alexis Viguié
** Last update Fri Dec  4 16:40:56 2015 Alexis Viguié
*/

#ifndef SAM_LIB_
# define SAM_LIB_
int	sam_strlen(char *str);
void	sam_putstr(char *str);
void	sam_putstr_err(char *str);
void	sam_put_error_and_exit(char *str, int errcode);
#endif /* SAM_LIB_ */
