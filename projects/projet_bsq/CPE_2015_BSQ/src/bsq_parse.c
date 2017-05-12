/*
** bsq_parse.c for bsq in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Dec 14 17:30:55 2015 Alexis Viguié
** Last update Sat Dec 19 00:22:13 2015 Alexis Viguié
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "sam.h"
#include "bsq.h"

int	get_row_number(char *filecontents)
{
  char	*number_char;
  int	counter;
  int	row_number_ret;

  counter = 0;
  while (filecontents[counter] != '\n')
    counter++;
  if ((number_char = malloc(sizeof(char) * (counter + 1))) == NULL)
    exit_mllc();
  counter = 0;
  while (filecontents[counter] != '\n')
    {
      number_char[counter] = filecontents[counter];
      counter++;
    }
  number_char[counter] = '\0';
  row_number_ret = sam_get_nbr(number_char);
  free(number_char);
  return (row_number_ret);
}

int	check_newlines(char *filecontents, int row_number)
{
  int	counter;
  int	newline_counter;

  counter = 0;
  newline_counter = 0;
  while (filecontents[counter] != '\n')
    counter++;
  counter++;
  while (filecontents[counter])
    {
      if (filecontents[counter] == '\n')
	newline_counter++;
      else if ((filecontents[counter] != '.') && (filecontents[counter] != 'o'))
	  return (0);
      counter++;
    }
  return (newline_counter == row_number);
}

int	check_rowsize(char *plat)
{
  int	row_size;
  int	frow_size;
  int	curr_pos;
  int	crow_size;

  frow_size = 0;
  while (plat[frow_size] != '\n')
    frow_size++;
  row_size = frow_size + 1;
  while (plat[row_size] != '\n' && plat[row_size])
      row_size++;
  if (plat[row_size] != '\n')
    return (1);
  row_size -= frow_size + 1;
  curr_pos = frow_size + row_size + 2;
  while (plat[curr_pos])
    {
      crow_size = 0;
      while (plat[curr_pos + crow_size] != '\n' && plat[curr_pos + crow_size])
	crow_size++;
      if (crow_size != row_size)
	return (0);
      curr_pos += crow_size + 1;
    }
  return (row_size);
}

char	*get_plat(char *filecontents, int row_number)
{
  int	counter;
  int	counter2;
  char	*plat_ret;

  if (!check_newlines(filecontents, row_number))
    return (NULL);
  counter = 0;
  while (filecontents[counter] != 'o' && filecontents[counter] != '.')
    counter++;
  counter2 = counter;
  while (filecontents[counter2])
    counter2++;
  if ((plat_ret = malloc(sizeof(char) * (counter2 - counter + 1))) == NULL)
    exit_mllc();
  counter2 = counter - 1;
  while (filecontents[counter2] && counter2++)
    plat_ret[counter2 - counter] = filecontents[counter2];
  plat_ret[counter2 - counter] = '\0';
  if (!check_rowsize(plat_ret))
    {
      free(plat_ret);
      return (NULL);
    }
  else
    return (plat_ret);
}
