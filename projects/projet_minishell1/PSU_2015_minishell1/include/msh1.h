/*
** msh1.h for minishell1 in /home/sam/Rendu/Projets/projet_minishell1/PSU_2015_minishell1/src
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Jan 17 19:37:14 2016 Alexis Viguié
** Last update Sat Mar 19 11:01:40 2016 Alexis Viguié
*/

#ifndef MSH1_H_
# define MSH1_H_

# define PATH_ENAME "PATH"
# define MSH1_PROMPT "$> "

# define MSH1_BUILTIN_CD "cd"
# define MSH1_BUILTIN_SETENV "setenv"
# define MSH1_BUILTIN_UNSETENV "unsetenv"
# define MSH1_BUILTIN_ENV "env"
# define MSH1_BUILTIN_EXIT "exit"

# define CD_USAGE "please specify a directory name\n"
# define CD_ERR_NOTFOUND ": directory not found\n"
# define CD_ERR_NOTAFOLDER ": directory a folder\n"
# define CD_ERR_ACCESS ": directory error\n"

# define SETENV_USAGE "please specify a variable name and then its contents\n"

# define UNSETENV_USAGE "please specify a variable name\n"
# define UNSETENV_ERR_NOTFOUND ": environment variable not found\n"

# define EXEC_NOTFOUND ": command not found\n"
# define EXEC_NOEXEC ": permission denied\n"

char	*msh1_getenv(char **ep, char *name);

int	msh1_parse_input(char *input, char **ep);

int	msh1_builtins(char **input, char **ep);
int	msh1_env_builtin_set(char **input, char **ep);
int	msh1_env_builtin_unset(char **input, char **ep);
void	msh1_env_builtin_disp(char **ep);

int	msh1_exec_command(char **input, char **ep);
int	msh1_get_exec_path(char *arg_with_path, char *name, char **path_var);

#endif /* !MSH1_H_ */
