/*
** marvin.h for marvin in /home/ruffetm/rendu/RUSH/marvin_ruffet_m/include
**
** Made by Mathieu RUFFET
** Login   <ruffetm@epitech.net>
**
** Started on  Sat May 14 10:00:01 2016 Mathieu RUFFET
** Last update Sat May 14 17:36:58 2016 Alexis Viguié
*/

#ifndef MARVIN_H_
# define MARVIN_H_

# define DEF_PTR "pointeur sur "
# define DEF_VAR "variable de type %s nommé %s"
# define DEF_FNC "fonction %s prenant en paramère un %s nommé %s et renvoyant un %s"
# define DEF_FNC_VOID "fonction %s qui ne prend rien en paramtre et renvoyant un %s"

# define DEF "Déclaration"
# define ART_PTR "du"
# define ART_VAR "de la"
# define ART_FNC "de la"
# define AND "et"

# define VAR_CHAR "caractère"
# define VAR_UCHAR "caractère non-signé"
# define VAR_SHORT "entier court"
# define VAR_USHORT "entier court non-signé"
# define VAR_INT "entier"
# define VAR_UINT "entier non-signé"
# define VAR_LONG "entier long"
# define VAR_ULONG "entier long non-signé"
# define VAR_LONGLONG "entier long long"
# define VAR_ULONGLONG "entier long long non signé"
# define VAR_FLOAT "réel flottant"
# define VAR_DOUBLE "double réel flottant"
# define VAR_LONGDOUBLE "double réel flottant long"
# define VAR_STRUCT "structure de nom %s"
# define VAR_UNION "union de nom %s"

# define NAME_CHAR "char"
# define NAME_SHORT "short"
# define NAME_INT "int"
# define NAME_LONG "long"
# define NAME_FLOAT "float"
# define NAME_DOUBLE "double"
# define NAME_UNSIGNED "unsigned"
# define NAME_STRUCT "struct"
# define NAME_UNION "union"

# define SYNTAX_ERROR "erreur de syntaxe"

# include <stddef.h>
# include <stdbool.h>

size_t	marvin_tablen(char **tab);
char	**my_str_to_wordtab(char *str);
bool	is_var(char *str);
void	disp_var(char **argtab);
char	*type_detection(char **argtab);
char	*remove_trailing_semicolon(char *name);

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

#endif /* !MARVIN_H_ */
