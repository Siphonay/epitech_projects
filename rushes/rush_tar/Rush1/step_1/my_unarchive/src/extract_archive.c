/*
** extract_archive.c for my tar in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat Jan  9 19:45:29 2016 Alexis Viguié
** Last update Sun Jan 10 17:24:11 2016 Alexis Viguié
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unarchive.h"
#include "errors.h"

void		extract_file(FILE *archive, char *fname, unsigned long fsize)
{
  unsigned long	counter;
  FILE		*file;

  file = fopen(fname, "wb+");
  counter = 0;
  while (counter < fsize)
    {
      fputc(fgetc(archive), file);
      counter++;
    }
  fclose(file);
}

void		extract_arc(FILE *archive)
{
  char		mnumber[MAGIC_SIZE];
  int		counter;
  int		file_number;
  size_t       	fname_len;
  char		*fname;
  unsigned long	cur_file_size;

  fread(mnumber, sizeof(char), MAGIC_SIZE, archive);
  if (strcmp(mnumber, MAGIC_NUMBER))
    exit_invalid_arc(archive);
  fread(&file_number, sizeof(int), 1, archive);
  counter = 0;
  while (counter < file_number)
    {
      fread(&fname_len, sizeof(size_t), 1, archive);
      if ((fname = malloc(sizeof(char) * (fname_len + 1))) == NULL)
	exit_mllc();
      fread(fname, sizeof(char), fname_len, archive);
      fname[fname_len] = '\0';
      fread(&cur_file_size, sizeof(unsigned long), 1, archive);
      extract_file(archive, fname, cur_file_size);
      printf("extracted: %s\n", fname);
      free(fname);
      counter++;
    }
}
