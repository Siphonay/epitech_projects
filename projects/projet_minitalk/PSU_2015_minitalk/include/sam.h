/*
** sam.h for minitalk in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Feb  8 17:05:44 2016 Alexis Viguié
** Last update Wed Feb 17 21:49:58 2016 Alexis Viguié
*/

#ifndef SAM_H_
# define SAM_H_

# define SAM_STDIN (1)
# define SAM_STDERR (2)

void	sam_putstr(char *str, int fd);
void	sam_putnbr(int nbr, int fd);

unsigned int	sam_strlen(char *str);

int	sam_str_to_int(char *str);
char	*sam_int_to_bin(int nb);
unsigned char	sam_bin_to_char(char *bin_str);

#endif /* !SAM_H_ */
