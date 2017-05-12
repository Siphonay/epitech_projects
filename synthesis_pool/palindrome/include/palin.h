/*
** palin.h for palindrome in /home/sam/Rendu/Piscine_S/palindrome
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Thu Jun 16 15:22:48 2016 Alexis Viguié
** Last update Sat Jun 18 16:47:25 2016 Alexis Viguié
*/

#ifndef PALIN_H_
# define PALIN_H_

# define PALIN_EXIT_SUCCESS 0
# define PALIN_EXIT_FAILURE 84

# define ERR_INVALID_ARG "invalid argument\n"
# define ERR_INCOMPATIBLE_ARG "incompatible arguments\n"
# define ERR_OOB "argument ouf of bonds\n"
# define ERR_NOARG "please specify your options. use -h for help.\n"

# define MSG_ITERATIONS "%i leads to %i in %i iteration(s) in base %i\n"
# define MSG_NOSOLUTION "no solution\n"

# define HELP_MESSAGE "USAGE\n\t"\
  "./palindrome -n number -p palindrome [-b base] [-imin i] [-imax i]\n\n"\
  "DESCRIPTION\n\t"\
  "-n nb\tinteger to be transformed (≥ 0)\n\t"\
  "-p pal\tpalindromic number to be obtained (incompatible with the −n option)"\
  " (≥ 0)\n\t\tif defined, all fitting values of n will be output\n\t"\
  "-b base\tbase in which the procedure will be executed (1 < b ≤ 10) [def: 10"\
  "]\n\t"\
  "-imin i\tminimum number of iterations, included (≥ 0) [def: 0]\n\t"\
  "-imax i\tmaximum number of iterations, included (≥ 0) [def: 100]\n"

# define OPTION_H "-h"
# define OPTION_N "-n"
# define OPTION_P "-p"
# define OPTION_B "-b"
# define OPTION_MIN "-imin"
# define OPTION_MAX "-imax"

# define DEFAULT_BASE 10
# define BASE_MAX 10
# define BASE_MIN 2
# define DEFAULT_MIN 0
# define DEFAULT_MAX 100

# define BASE_TEN "0123456789"

# include <stdbool.h>

typedef struct	s_options
{
  bool		help;
  bool		num;
  bool		pal;
  int		value;
  int		base;
  int		imin;
  int		imax;
  bool		invalid_arg;
}		t_options;

t_options	palin_parse_options(char **av);
bool		palin_validate_options(t_options options);
int		palin_print_help(void);
int		palin_sarah(t_options options);

char	*palin_revstr(char *str);
int	is_a_palindrome(char *str);
char	*int_to_base_str(int nb, char *base);

void	aux_nosolution(bool solution);
bool	aux_print_number(t_options options, int nb, int counter);
bool	aux_print_palindrome(t_options options, int counter, int counter2);
int	aux_free(char *s1, char *s2, int nb);

#endif /* !PALIN_H_ */
