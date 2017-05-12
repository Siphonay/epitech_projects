/*
** create_arc.c for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 11:24:56 2016 Alexis Viguié
** Last update Sun Jan 10 18:23:47 2016 Alexis Viguié
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "tek_arc.h"

char	*get_rname(char *name)
{
  int	counter;
  int	slashpos;
  char	*ret_name;

  counter = 0;
  slashpos = -1;
  while (name[counter])
    {
      if (name[counter] == '/')
	slashpos = counter;
      counter++;
    }
  if ((ret_name = malloc(sizeof(char) * (strlen(name) - slashpos))) == NULL)
    exit_mllc();
  return (strcpy(ret_name, &name[slashpos + 1]));
}

unsigned long	get_fsize(FILE *cur_file)
{
  unsigned long	size;

  fseek(cur_file, 0, SEEK_END);
  size = ftell(cur_file);
  fseek(cur_file, 0, SEEK_SET);
  return (size);
}

FILE	*create_empty_arc(char *arcname)
{
  FILE	*arc_ret;

  arc_ret = fopen(arcname, "wb+");
  fwrite(MAGIC_NUMBER, sizeof(char), MAGIC_SIZE, arc_ret);
  return (arc_ret);
}

void		create_arc(FILE **file_list, char **args, int file_number)
{
  FILE		*arcf;
  int		counter;
  char		*cur_relname;
  size_t        cur_fname_len;
  int		cur_char;
  unsigned long cur_fsize;

  arcf = create_empty_arc(args[1]);
  fwrite(&file_number, sizeof(int), 1, arcf);
  counter = 0;
  while (counter < file_number)
    {
      cur_relname = get_rname(args[counter + 2]);
      cur_fname_len = strlen(cur_relname);
      fwrite(&cur_fname_len, sizeof(size_t), 1, arcf);
      fwrite(cur_relname, sizeof(char), cur_fname_len, arcf);
      cur_fsize = get_fsize(file_list[counter]);
      fwrite(&cur_fsize, sizeof(unsigned long), 1, arcf);
      while ((cur_char = fgetc(file_list[counter])) != EOF)
	fputc(cur_char, arcf);
      printf("archived: %s\n", cur_relname);
      free(cur_relname);
      counter++;
    }
  fclose(arcf);
}
