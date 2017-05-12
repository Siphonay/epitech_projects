/*
** bistromathique.h for bistromatique in /home/coutar_b/rendu/Piscine_C_bistromathique/Piscine_C_bistromathique_test
** 
** Made by Thomas Coutard
** Login   <coutar_b@epitech.net>
** 
** Started on  Fri Oct 23 15:46:09 2015 Thomas Coutard
** Last update Fri Oct 23 16:07:47 2015 Thomas Coutard
*/

void	*malloc(unsigned int);

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define SYNTAXE_ERROR_MSG "syntax error"

char	*eval_expr(char *base, char *ops, char *expr, unsigned int size);
