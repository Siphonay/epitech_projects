/*
** check_board.c for Colle in /home/joly_r/rendu/Colles/Colle2/Colle2/src
**
** Made by joly_r
** Login   <joly_r@epitech.net>
**
** Started on  Tue May  3 15:49:00 2016 joly_r
** Last update Tue May  3 17:32:53 2016 Alexis Viguié
*/

#include "p4.h"

char	check_line(char **board, char avatar, t_p4_opts *option)
{
  int	i;
  int	cmptr;
  int	a;

  i = 0;
  a = 1;
  cmptr = 0;
  while (i < option->height)
    {
      while (board[i][a] != '\0')
	{
	  if (board[i][a] == avatar)
	    cmptr++;
	  else
	    cmptr = 0;
	  if (cmptr == 4)
	    return (avatar);
	  a++;
	}
      a = 1;
      cmptr = 0;
      i++;
    }
  return ('N');
}

char	check_col2(char**board, char avatar, t_p4_opts *option)
{
  int	i;
  int	a;
  int	cmptr;

  cmptr = 0;
  i = 0;
  a = 1;
  while (a < option->width)
    {
      while (i < option->height)
	{
          if (board[i][a] == avatar)
            cmptr++;
          else
            cmptr = 0;
          if (cmptr == 4)
            return (avatar);
          i++;
	}
      i = 0;
      a++;
      cmptr = 0;
    }
  return ('N');
}

  char	check_board(char **board, char avatar, t_p4_opts *option)
{
  if ((check_line(board, avatar, option)) == avatar)
    return (avatar);
  if ((check_col2(board, avatar, option)) == avatar)
    return (avatar);
  return ('N');
}
