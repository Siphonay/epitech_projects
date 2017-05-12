/*
** sbml.h for SBMLparser in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Mon Jun 13 09:42:21 2016 Alexis Viguié
** Last update Wed Jun 15 16:52:13 2016 Alexis Viguié
*/

#ifndef SBML_H_
# define SBML_H_

# define SBML_EXIT_FAILURE 84
# define SBML_EXIT_SUCCESS 0

# define LINE_LEVEL "----->"

# define STRING_SPECIES "List of species"
# define STRING_COMP "List of species in compartement "
# define STRING_REACTION "List of reactions consuming species "
# define STRING_REACTION_END " (quantities)"
# define STRING_ACTION "->"
# define STRING_REVERSIBLE_ACTION "<->"
# define STRING_PLUS "+"

# define ERR_NAME "SBMLparser: "
# define ERR_STRING_OPTION "unknown '%s' parameter\n"
# define ERR_HELP "help must be called without anything else\n"
# define ERR_NOARG "no argument. use option -h for help\n"
# define ERR_NOFILE "file '%s' not found or not openable\n"

# define HELP_USAGE "USAGE"
# define HELP_CLINE "./SBMLparser SBMLfile [-i ID [-e]] [-json]"
# define HELP_DESCRIPTION "DESCRIPTION"
# define HELP_FILE "SBMLfile\tSBML file"
# define HELP_I "-i ID\tid of the compartment, reaction or product to be extrac"
# define HELP_I2 "ted (ignored if uncorrect)"
# define HELP_E "-e\tprint the equation if a reaction ID is given as argument ("
# define HELP_E2 "ignored otherwise)"
# define HELP_JSON "-json\ttransform the file into a JSON file"

# define OPTION_I_STR "-i"
# define OPTION_E_STR "-e"
# define OPTION_H_STR "-h"
# define OPTION_J_STR "-json"
# define OPTION_I 1
# define OPTION_E 2
# define OPTION_H 3
# define OPTION_J 4

# include <stdbool.h>

typedef struct	s_options
{
  int		fd;
  char		*id;
  bool		reaction;
  bool		json;
  bool		help;
  bool		correct;
  char		*invalidarg;
  bool		noarg;
  bool		help_afterarg;
}		t_options;

char		**str_lines_to_wordtab(char *str);
void		free_wordtab(char **wordtab);
int		print_help();
t_options	parse_options(char **av);
int		sbml_error_handling(t_options options, char *filename);
int		sbml_parsing(t_options options);
char		*get_quoted_str(char *str, char quote);
char		**append_to_wordtab(char **wordtab, char *str_to_append);

#endif /* !SBML_H_ */
