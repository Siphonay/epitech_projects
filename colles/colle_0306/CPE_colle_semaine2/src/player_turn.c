/*
** player_turn.c for Colle in /home/joly_r/rendu/Colles/Colle2/Colle2/src
** 
** Made by joly_r
** Login   <joly_r@epitech.net>
** 
** Started on  Tue May  3 15:33:23 2016 joly_r
** Last update Tue May  3 16:30:31 2016 joly_r
*/

#include "my.h"
#include "p4.h"

int	check_col(int col, int width)
{
  if (col < 1)
    return (-1);
  if (col > width)
    return (-1);
  return (0);
}

int	my_prompt(char avatar, t_p4_opts option)
{
  char	buff[512];
  int	len;
  int	col;

  col = 0;
  while (check_col(col, option.width) != 0)
    {
      my_putstr("Player ");
      my_putchar(avatar);
      my_putstr(", where do you want to play: ");
      len = read(0, buff, 512);
      buff[len - 1] = '\0';
      col = my_get_nbr(buff);
    }
  return (col);
}

int	fill_board(char **board, int col, t_p4_opts option, char avatar)
{
  int	i;

  i = option.height;
  if (col == -1)
    return (-1);
  while (board[i][col] != ' ')
    {
      i--;
      if (i == -1)
	return (-1);
    }
  board[i][col] = avatar;
  return (0);
}

int	player_turn(char **board, char avatar,  t_p4_opts option)
{
  int	col;

  col = -1;
  while ((fill_board(board, col, option, avatar)) == -1)
    col = my_prompt(avatar, option);
  print_board(board);
  return (0);
}
