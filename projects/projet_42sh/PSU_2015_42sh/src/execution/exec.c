/*
** exec.c for 42sh in /home/nolann/Documents/Projet/PSU/PSU_2015_42sh/src/
**
** Made by Nolann Méléard
** Login   <melear_n@epitech.eu>
**
** Started on  Tue May 24 18:38:12 2016 Nolann Méléard
** Last update	Sun Jun 05 20:28:38 2016 pedron_s
*/

#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "mysh.h"

char    *my_strnncpy(char *dest, char *src, int n)
{
  int   j;
  int	i;

  j = n;
  i = 0;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j++;
      i++;
    }
  return (dest);
}

char	**tab_exec(int a, char **av, char **env, t_data *data)
{
  (void)data;

  int	(*t_ptri[6])(char **av, char **env, t_data *data);
  int	(*t_ptr[2])(char **av, char **env);
  t_ptri[0] = &builtin_setenv;
  t_ptri[1] = &builtin_unsetenv;
  t_ptri[2] = &my_cd;
  t_ptri[3] = &alias;
  t_ptri[4] = &which;
  t_ptri[5] = &where;
  t_ptr[0] = &print_env;
  t_ptr[1] = &echo;
  if (a < 4)
    t_ptr[a](av, env);
  else
    t_ptri[a - 4](av, data->env, data);
  return (data->env);
}

int	built_ins(char **av)
{
  int	a;

  a = -1;
  if (strcmp(av[0], ENV) == 0)
    {
      if (av[1] != NULL)
	return (-1);
      return (0);
    }
  if (strcmp(av[0], SETENV) == 0)
    return (4);
  if (strcmp(av[0], UNSETENV) == 0)
    return (5);
  if (strcmp(av[0], WHICH) == 0)
      return (8);
  if (strcmp(av[0], WHERE) == 0)
    return (9);
  if (strcmp(av[0], ECHO) == 0)
    return (1);
  if (strcmp(av[0], CD) == 0)
      return (6);
  if (strcmp(av[0], ALIAS) == 0)
    return (7);
  return (a);
}

int	execute_with_fd(int fd[2], t_data *data, int i, char **av)
{
  if (fd[0] != -2 && fd[0] != -1)
    dup2(fd[0], STDIN_FILENO);
  if (fd[1] != -2 && fd[1] != -1)
    dup2(fd[1], STDOUT_FILENO);
  if (fd[0] != -2 && fd[0] != -1)
    close(fd[0]);
  if (fd[1] != -2 && fd[1] != -1)
    close(fd[1]);
  setpgid(getpid(), getpid());
  if (i == -1)
    data->env = get_exec(av, data->env, data);
  return (0);
}

int	my_exec(char **env, char **av, t_data *data, int fd[2])
{
  int	i;
  int	pid;
  int	status;

  if (env == NULL)
    return (1);
  if ((i = built_ins(av)) != -1)
    data->env = tab_exec(i , av, env, data);
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      execute_with_fd(fd, data, i, av);
      exit(data->exec);
    }
  if (pid > 0)
    {
      tcsetpgrp(STDIN_FILENO, pid);
      waitpid(pid, &status, 0);
      tcsetpgrp(STDIN_FILENO, getpgid(getpid()));
      if (status >= 128 && status <= 139)
	dprintf(STDERR_FILENO, "Segmentation fault (core dumped)\n");
    }
  return (0);
}
