/*
** word_evaluate.c for my scrabble in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Nov 26 16:53:12 2015 Alexis Viguié
** Last update Fri Nov 27 09:01:56 2015 Alexis Viguié
*/

#include <unistd.h>
#include <stdlib.h>
#include "scrabble.h"

int	word_evaluate(char *word, int *letter_vals)
{
  int	counter;
  int	word_val;

  counter = 0;
  word_val = 0;
  while (word[counter])
    {
      word_val += letter_vals[word[counter] - 'A'];
      counter++;
    }
  return (word_val);
}

int	scrabble_eval(int scrabble_fd)
{
  int	word_count;
  int	word_vals[26];
  char	tmp_char[4];
  char	**words;
  int	counter;
  int	counter2;
  int	vals_counter;
  char	file_buff[2048];

  counter = 0;
  read(file_buff, file_buff, 2048);
  while (file_buff[counter] != '\n')
    {
      tmp_char[counter] = file_buff[counter];
      counter++;
    }
  counter++;
  word_count = my_get_nbr(tmp_char);
  free(tmp_char);
  vals_counter = 0;
  counter2 = 0;
  while (vals_counter < 26)
    {
      if (file_buff[counter] == ' ')
	{
	  word_vals[vals_counter] = my_get_nbr(tmp_char);
	  vals_counter++;
	  free(tmp_char);
	  counter++;
	  counter2 = 0;
	}
      else
	{
	  tmp_char[counter2] = file_buff[counter];
	  counter++;
	  counter2++;
	}
    }
    words = malloc(word_count);
    counter2 = 0;
    while (counter2 < word_count)
      {
	vals_counter = 0;
	while (file_buff[counter] != '\n')
	  {
	    vals_counter++;
	    counter++;
	  }
	words[counter2] = malloc((vals_counter + 1] * sizeof(char));
	counter -= vals_counter;
	while (counter < vals_counter)
	  {
	    while (counter < vals_counter)
	      {
		words[counter2][counter + (counter - vals_counter)] = file_buff[counter];
		counter++;
	      }
	  }
      }
}
