/*
** xo.h for tic tac toe in /home/sam/Rendu/Red Alert/redaltert_tictactoe/RA_TICTACTOE/include
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Feb 10 09:19:01 2016 Alexis Viguié
** Last update Wed Feb 10 10:04:45 2016 Alexis Viguié
*/

#ifndef XO_H_
# define XO_H_

#include <ncurses.h>
#include <stdbool.h>

typedef struct		s_winsize
{
  unsigned short	x;
  unsigned short	y;
}			t_winsize;

typedef t_winsize	t_xopos;

void	exit_wintoosmall();
#define WTS_M "error: Window too small. Please resize your window to 6x6 min.\n"

bool	xo_play();

#define XO_MIN_SIZE (6)

#define XO_GRID " | | \n-----\n | |\n-----\n | |"
#define XO_SYMBOLS " XO"

#define X_TURN_MSG "X TURN "
#define O_TURN_MSG "O TURN "

#define X_WIN "X WINS!"
#define O_WIN "O WINS!"
#define TIE_GAME "TIE!  "

#endif /* !XO_H_ */
