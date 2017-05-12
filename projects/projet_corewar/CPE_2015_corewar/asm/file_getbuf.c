/*
** file_getbuf.c for corewar in /home/sam/Rendu/Projets/projet_corewar/CPE_2015_corewar/my_asm
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Tue Mar 22 10:05:14 2016 Alexis Viguié
** Last update Wed Mar 30 09:45:33 2016 Victor Herlin
*/

#include <asm.h>

char	**file_getbuf_in_tab(int fd)
{
  char	*ret_str;
  int	file_size;
  char	**tab;

  if ((file_size = lseek(fd, 0, SEEK_END)) == -1 ||
      lseek(fd, 0, SEEK_SET) == -1 ||
      (ret_str = malloc(sizeof(char) * (file_size + 1))) == NULL ||
      read(fd, ret_str, file_size) < file_size ||
      (tab = my_str_to_wordtab(ret_str, '\n')) == NULL ||
      (tab = clean_tab_first_spaces(tab)) == NULL)
    return (NULL);
  tab = clean_tab_first_spaces(tab);
  return (tab);
}
