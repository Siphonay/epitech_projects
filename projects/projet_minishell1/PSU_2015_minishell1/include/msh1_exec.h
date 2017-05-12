/*
** msh1_exec.h for minishell1 in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Wed Jan 27 21:56:54 2016 Alexis Viguié
** Last update Wed Jan 27 23:18:23 2016 Alexis Viguié
*/

#ifndef MSH1_EXEC_H_
# define MSH1_EXEC_H_

void	exec_puterr(char *name, char *err);
void	path_puterr(char *name, int err);
int	access_file(char *name);
int	exec_path_free_exit(char **path_var);
unsigned int	access_file_path(char *name);

#endif /* !MSH1_EXEC_H_ */
