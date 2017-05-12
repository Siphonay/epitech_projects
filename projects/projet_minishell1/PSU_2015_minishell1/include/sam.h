/*
** sam.h for sam lib in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Fri Dec  4 14:41:28 2015 Alexis Viguié
** Last update Wed Jan 27 18:37:16 2016 Alexis Viguié
*/

#ifndef SAM_H_
# define SAM_H_

unsigned int	sam_strlen(char *str);

void	sam_putstr(char *str);
void	sam_putstr_err(char *str);

int	sam_get_nbr(char *str);

unsigned int	sam_strcmp(char *pstring_1, char *pstring_2);

int	sam_strncmp(char *pstring_1, char *pstring_2, unsigned int c_lim);
char	*sam_strncpy(char *param_string, unsigned int c_lim);
char	*sam_strncat(char *str_1, char *str_2, unsigned int c_lim);

char	**sam_strtab(char *src, char *separator);
char	**sam_strtabcpy(char **src);
char	**sam_strtab_add(char **src, char *str_add);
char	**sam_strtab_rm(char **src, unsigned int index);
void	sam_free_strtab(char **strtab);
unsigned int	sam_strtablen(char **strtab);

# define READ_SIZE (14)
# define STDIN_FD (0)
char	*sam_gets(int fd);

#endif /* !SAM_H_ */
