/*
** parsing_bis.c for parsing in /home/zaza/rendu/PSU_2015_minishell2/SRCS/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Sat Apr  9 11:49:57 2016 thibault derbre
** Last update Sat Apr  9 11:50:58 2016 thibault derbre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"

t_list	*lex_pars(t_list *lex, t_data *data, char *str)
{
  data->j = 0;
  data->flag = 0;
  data->compt = 0;
  data->len = my_strlen(str);
  if ((str = epur_str(str)) == NULL)
    return (NULL);
  str = delete_token_spaces(str);
  lex = pars_tokens(lex, str, data);
  return (lex);
}

t_list	*pars_tokens(t_list *lex, char *str, t_data *data)
{
  data->flag = 0;
  if ((data->src = malloc(data->len + 1 * sizeof(char))) == NULL)
    exit (1);
  while (str[data->j] != '\0')
    {
      while (str[data->j] != '\0')
	{
	  data->src[data->compt] = str[data->j];
	  if ((check_tokens(str, &(data->j), &(data->flag),
			    &(data->compt))) == 1)
	    break;
	  if ((check_cmd(str, &(data->j), &(data->flag), &(data->compt))) == 1)
	    break;
	  data->compt++;
	  data->j++;
	}
      data->src[data->compt] = '\0';
      lex = my_put_in_list(lex, data->src, data);
      if (str[data->j] == '\0')
	break;
      data->compt = 0;
      if ((data->src = malloc(data->len + 1 * sizeof(char))) == NULL)
	exit (1);
    }
  return (lex);
}
