/*
** get_next_line.h for get_next_line in /home/zaza/rendu/PSU_2015_minishell2/include/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 17:36:58 2016 thibault derbre
** Last update Mon Apr  4 17:53:26 2016 thibault derbre
*/

#ifndef LINE_H_
# define LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (30)
# endif /* !READ_SIZE */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_getline
{
  int		i;
  int		fd;
  char 		*line;
  char		*buffer;
} t_getline;

char		*get_next_line(const int fd);
int		rimka(char *str, int cmp, ssize_t read_check);
char		*my_strcat_get(char *str1, char *str2);
char		*my_strcpy(int i, char *str2, int *cmp);
void		my_mem_set(char **table, int size);
void		go_to_zero(int *cmp, ssize_t *read_check, char *wait);
void		my_mem_set(char **table, int size);
char		*get_started(t_getline *getline, char *wait,
			     ssize_t *read_check);
char		*loop_read(t_getline *getline, char *wait, int *cmp,
                             		   ssize_t *read_check);
#endif /* LINE_H_ */
