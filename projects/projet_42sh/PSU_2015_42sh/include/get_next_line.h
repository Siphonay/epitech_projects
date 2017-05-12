/*
** get_next_line.h for get_next_line in /home/zaza/rendu/PSU_2015_42sh/include/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Wed May  4 14:38:26 2016 thibault derbre
** Last update Thu May 19 15:19:21 2016 Alexis Viguié
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (30)
# endif /* !READ_SIZE */

typedef struct s_getline
{
  int		i;
  int		fd;
  char 		*line;
  char		*buffer;
}		t_getline;

# include <sys/types.h>

void		my_mem_set(char **table, int size);
char		*my_strcpy(int i, char *str2, int *cmp);
char		*my_strcat_get(char *str1, char *str2);
int		check_read(char *str, int cmp, ssize_t read_check);
char		*get_next_line(const int fd);
void		go_to_zero(int *cmp, ssize_t *read_check, char *wait,
			   t_getline *getline);
char		*loop_read(t_getline *getline, char *wait, int *cmp,
			   ssize_t *read_check);
char		*get_started(t_getline *getline, char *wait,
			     ssize_t *read_check);

#endif /* !GET_NEXT_LINE_H_ */
