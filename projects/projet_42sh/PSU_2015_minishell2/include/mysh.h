/*
** mysh.h for mysh in /home/zaza/rendu/PSU_2015_minishell2/include/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr  4 17:16:57 2016 thibault derbre
** Last update Tue Apr 12 18:56:03 2016 thibault derbre
*/

#ifndef MYSH_H
# define MYSH_H

typedef struct s_data
{
  char		**original_env;
  char		**env;
  int		exit_nb;
  int		max_col_env;
  int		value;
  int		nb_cmd;
  int		id;
  int		if_path;
  int		if_exit;
  int		exit_id;
  char		*command;
  char		*full_cmd;
  char		**args;
  char		*path;
  char		*path_directories;
  int		path_pos;
  int		end_instructions;
  int		exc;
  int		len;
  int		compt;
  int		flag;
  int		j;
  char		*src;
  int		exec_over;
  char		*pwd;
  char		*oldpwd;
} t_data;

typedef struct s_list
{
  char		*cmd;
  char		**args;
  char		*stdin;
  char		*stdin_path;
  char		*stdout;
  char		**stdout_path;
  int		is_piped;
  int		is_piping;
  int		id;
  struct s_list *next;
  struct s_list *prev;
} t_list;

/* basic */

void		my_putchar(char c);
void		my_putstr(char *str);
int		my_strlen(char *str);
int		my_strcmp_env(char *str, char *buff);
int		my_strcmp_setenv(char *str, char *buff);
char		*epur_str(char *str);
int		my_strcmp(char *s1, char *s2);
char		*my_strcat_cd(char *dest, char *src);
int		my_strncmp(char *s1, char *s2, int n);
int		my_getnbr(char *str);

/* table */

char		**create_char_table(int nblin, int nbcol);
void		free_char_table(char **tableau);
void		show_table(char **table);
char		**str_to_wordtab(char *str);

/* env */

t_data		*copy_env(t_data *data, char **env);
t_data		*copy_var_env(t_data *data, char **env);
void		take_var_env(char **env, int *lines, int *col);
void		show_prompt(t_data *data);

/* mysh */

t_data		*my_sh(t_data *data);
void		init_var(t_data *data);
void		launch_commands(t_data *data, t_list *lex);
int		builtins(t_data *data);
t_list		*fill_data_cmd(t_data *data, t_list *lex);
void		show_error(t_data *data);

/* parsing */

char		*get_next_line(const int fd);
char		*delete_token_spaces(char *str);
int		check_tokens(char *str, int *j, int *f, int *compt);
int		check_cmd(char *str, int *j, int *f, int *compt);
t_list		*pars_tokens(t_list *lex, char *str, t_data *data);
t_list		*lex_pars(t_list *lex, t_data *data, char *str);
char		*pars_cmd(char *str);

/* list */

void		my_list_free(t_list *lex, t_data *data);
t_list		*fill_elem(t_list *elem, char *str, t_data *data);
t_list		*my_put_in_list(t_list *lex, char *str, t_data *data);

/* buildings */

void		my_cd(t_data *data);
void		my_env(t_data *data);
void		my_unsetenv(t_data *data);
void		my_set_env(t_data *data);
void		my_exit(t_data *data);

/* setenv */

char		**add_the_var(char **table, int y, t_data *data);
void		delete_value(t_data *data, int y);
void		change_value(t_data *data, int y);
void		realloc_table(t_data *data, int col);

/* cd */

void		remote_cd_directory(t_data *data);
void		change_the_directory(t_data *data);
void		old_directory(t_data *data);
int		change_begin_home(t_data *data);
int		change_add_home(t_data *data);
void		change_env_var(t_data *data);
void		cd_home(t_data *data);
void		fill_data_var_cd(t_data *data, int *i, int *y, int *j);

#endif /* MYSH_H */
