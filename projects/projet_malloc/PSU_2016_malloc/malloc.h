/*
** malloc.h for malloc in /home/sam/Rendu/Projets/projet_malloc/malloc_test
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Feb  1 16:14:25 2017 Alexis Viguié
** Last update Sat Feb 11 17:22:20 2017 Alexis Viguié
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <sys/types.h>
# include <unistd.h>

# define align4(x) (((((x) - 1) >> 2) << 2) + 4)
# define BLOCK_SIZE sizeof(struct s_block)


typedef struct		s_block
{
  size_t		size;
  struct s_block	*next;
  struct s_block	*prev;
  int			free;
  void			*ptr;
  char			data[1];
}			*t_block;

extern t_block	base;

void	*malloc(size_t size);
void	free(void *p);
void	*realloc(void *p, size_t size);
void *malloc_nobbase(t_block last, size_t s);
void *fonction(t_block nul, size_t s, t_block b);
void *pointeur_null(void *new_pointeur, size_t s, t_block b, void *p);

t_block	find_block(t_block *last, size_t size);
void	split_block(t_block b, size_t size);
void	*malloc_nobase(t_block last, size_t s, t_block b);
void	copy_block(t_block src, t_block dst);
t_block	extend_heap(t_block last, size_t s);
t_block get_block(void *p);
t_block	fusion(t_block b);
int	valid_addr(void *p);

#endif /* !MALLOC_H_ */
