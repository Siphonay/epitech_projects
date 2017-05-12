/*
** p4.h for colle2 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue May  3 14:20:40 2016 Alexis Viguié
<<<<<<< HEAD
** Last update Tue May  3 17:30:02 2016 joly_r
=======
** Last update Tue May  3 14:31:34 2016 joly_r
>>>>>>> 69cb76b71a4149e80fdc9f917902d1112b8f656a
*/

#ifndef P4_H_
# define P4_H_

# include <stdbool.h>

typedef struct	s_p4_opts
{
  int		width;
  int		height;
  char		p1_avatar;
  char		p2_avatar;
  char		a_avatar;
  bool		ia;
}		t_p4_opts;

# define DEFOPS_W 7
# define DEFOPS_H 6
# define DEFOPS_P1 'X'
# define DEFOPS_P2 'O'
# define DEFOPS_A '#'
# define DEFOPS_IA false

# define OP_W "-w"
# define OP_H "-h"
# define OP_P1 "-p1"
# define OP_P2 "-p2"
# define OP_A "-a"
# define OP_IA "-ia"

int	        p4_parse_options(char **args, t_p4_opts *options);
int		p4_game_loop(t_p4_opts *options);
void	        ia_turn(char **board, char avatar, t_p4_opts option);
int	        err_usage(const char *invalid_param, const char *bin_name,
			  t_p4_opts *options);
int	        err_bad_param(const char *invalid_val, const char *param_name,
			      t_p4_opts *options);
bool	        check_parser_errors(t_p4_opts *options);
int	        player_turn(char **board, char avatar,  t_p4_opts option);
char	        check_board(char **board, char avatar, t_p4_opts *option);
void	        end_game(char **board, char a);
void	        print_board(char **board);
int	        fill_board(char **board, int col,
			   t_p4_opts option, char avatar);

#endif /* !P4_H_ */
