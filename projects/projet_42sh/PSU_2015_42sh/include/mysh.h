/*
** 42.h for 42 in /home/zaza/rendu/PSU_2015_42sh/include/
**
** Made by thibault derbre
** Login   <derbre_t@epitech.eu>
**
** Started on  Mon Apr 18 13:35:34 2016 thibault derbre
** Last update	Sun Jun 05 18:14:38 2016 pedron_s
*/

#ifndef MYSH_H_
# define MYSH_H_

# define SEG 139
# define COLOR \033[34m
# define UNCOL \033[0m

# define ENV_EXIT_FAILURE 84
# define UNSETENV_NOVAR 2
# define ENV_VAR_SEPARATOR '='

# define ENV "env"
# define SETENV "setenv"
# define UNSETENV "unsetenv"
# define CD "cd"
# define ECHO "echo"
# define WHICH "which"
# define WHERE "where"
# define EXIT "exit"
# define ALIAS "alias"

# define SETENV_INVALID_VAR "invalid variable name"
# define SETENV_EMPTY ""
# define UNSETENV_USAGE "unsetenv var"

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include "exit_doop.h"
# include "liste.h"

typedef struct s_file
{
  char		**tab;
  char		*param;
}		t_file;

typedef struct s_data
{
  t_file	*file;
  char		**env;
  char		*pwd;
  char		*oldpwd;
  char		*tmp_pwd;
  char		*tmp_old;
  int		is_in;
  int		is_out;
  char		**args;
  int		nb_pipe;
  int		is_piped;
  int		exec;
  int		fail;
  pid_t		pid;
}		t_data;

/*
** base
*/

size_t          wordtablen(char **);
int		my_putstr(char *);
void		my_putchar(char);
int		my_getnbr(const char *);

/*
** command
*/

t_data		*launch_commands(t_data *);
t_list		init_list(t_data *, char *);
char		*epur_str(char *);
int		my_list(char *, t_list *);
char		**my_str_to_wordtab(char *, char *, int, int);
void		initialisation_liste(t_list *);
int		add_list(t_list *, int, char **, int);
void		show_pos(t_list *, char *);
char		*delete_token_spaces(char *);

/*
** env_builtins
*/

int		builtin_unsetenv(char **, char **, t_data *);
int		builtin_setenv(char **, char **, t_data *);
int		print_env(char **, char **);
int		check_env(char *, char **);
int		print_setenv_usage(char **);
int		print_unsetenv_usage(void);
int		invalid_env_name(void);
char		*build_env(char *, char *);
int		append_env(char *, char *, char **);
bool		check_validvar(char *);
char		**shift_var(char **, int);

/*
** execution
*/

char		*my_strnncpy(char *, char *, int);
char		**tab_exec(int, char **, char **, t_data *);
int		built_ins(char **);
int		execute_with_fd(int fd[2], t_data *, int, char **);
int             my_exec(char **, char **, t_data *, int fd[2]);
int             search_path(char **);
void            get_free_tab(char **, int);
char		*real_path(char **, int, char *, int);
char            *get_path(char **, char **);
char		**get_exec(char **, char **, t_data *);
char		*check_here(char **);
char            *my_memset(char *, char, int);
int		search_pwd(char **);
char            *copy_arg(char  *, char **);
char            *get_dot_slash(char **, char **);
int             count_sep(char *, char);
char            **doublearray(int, int);
char            *endcopy(char *, int, char *);
char            **fill_tab(char **, int, char *, char **);
int             get_access(char **, int);
char		**get_env(char **);

/*
** cd
*/

void            fill_data_var_cd(t_data *, int *, int *, int *);
int             take_var_len(t_data *, char *);
int             change_data_var(t_data *);
int             cd_home(t_data *);
int             change_old_var(t_data *);
void            old_directory(t_data *);
char            *my_strcat_cd(char *, char *);
int             change_add_home(t_data *);
int             change_begin_home(t_data *);
void            my_change_directory(t_data *);
void            change_the_directory(t_data *);
void            change_env_var_cd(int, t_data *, int);
int             my_strcmp(char *, char *);
int             my_strcmp_setenv(char *, char *);
int		my_cd(char **, char **, t_data *);
void		change_env_var(t_data *);
int		remote_cd_directory(t_data *);
int		change_data_remote(t_data *);

/*
** token parsing
*/

int		function_pipe(t_elem *, t_data *, int pipes[2]);
int		check_tokens(t_list);
int		check_commands(t_list);
t_list		pars_token(t_list, t_data *);
int		check_redirect(char *);
char		**create_char_table(int, int);
int		exec_pipe(char **, char **, t_data *, int fd[2]);
char		**fill_cmd_table(t_elem *, char **, int);
void		execute_with_flow(t_elem *, char **, t_data *, int);
int		check_flow_command(t_list);
t_data		*get_file(t_data *);
char		**calc_cmd_table(t_elem *, int *);
void		prepare_pipe_exec(t_elem *, t_data *);
int		fill_flow(int fd[2], int pipes[2], t_data *);
int		check_flow(char *);
int		check_pipes(t_elem *elem,  t_data *data);

/*
** Exit_builtin
*/

bool		my_isalpha(char *);
t_exitval       aux_doop(char **, int, t_exitval);
void            free_wordtab(char **);
void		exit_builtin(t_elem *, char **, char **, t_data *);
void            get_free_file(t_data *);

/*
** Echo
*/

int		my_pars(char **);
int		my_parspar(char **);
void		my_error(int);
void		my_dis(char **, int);
int		echo(char **, char **);

/*
** Signal
*/

void		init_signal(void);
int		my_kill(char **, char **);

/*
** where.c and which.c
*/

int		where(char **, char **, t_data *);
char		**fill_tab_where(int, int, char *, char *);
void		get_where(char **, int);
int             find_alias(char *, t_data *);
char            *which_path(char *, int);
int             which(char **, char **, t_data *);

/*
** Conf file
*/

char		**copy_rest(char **, int, char **);
char		**cpy_alias_tab(char **, int, char **);
char		**get_alias_tab(char **);
int             alias(char **, char **, t_data *);
int		load_alias(char	**, t_data *);
t_file		*first_init_file(void);
t_file		*count_and_realloc_file(t_file *, int *);
int		charisalphanum(char, char, char);
int		verif_export(char *);
char		**get_cmd(char *);
int             export(char **, t_data *);
char            *get_name(char *);
int		check_for_av1(char *);
int		check_for_avx(char **);
int             count_for_alias(char **);
int             count_len_tab(char **);
char		**load_file(void);
t_data          *get_file(t_data *);
int		get_x(char **, t_file *, int, int *);
char		**fill_cmd_alias(char **, t_file *, int);
char            **is_this_an_alias(char **, t_data *);
char		*check_here(char **);
int		find_alias(char *, t_data *);
char		*which_path(char *, int);

#endif /* !MYSH_H_ */
