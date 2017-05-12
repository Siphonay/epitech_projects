/*
** minishell1_main.c for minishell1 in /home/sam/Rendu/Projets/projet_minishell1/PSU_2015_minishell1/src
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sun Jan 17 18:33:07 2016 Alexis Viguié
** Last update Wed Jan 27 23:43:36 2016 Alexis Viguié
*/

#include <stdlib.h>
#include <unistd.h>
#include "msh1.h"
#include "sam.h"

char	*get_prompt()
{
  sam_putstr(MSH1_PROMPT);
  return (sam_gets(STDIN_FD));
}

int	main(int __attribute__((unused)) ac, char __attribute__((unused)) **av,
	     char **ep)
{
  char	*stdin_s;
  char	**runtime_ep;

  if ((runtime_ep = sam_strtabcpy(ep)) == NULL)
    return (1);
  while (msh1_parse_input((stdin_s = get_prompt()), runtime_ep) >= 0)
    free(stdin_s);
  sam_free_strtab(runtime_ep);
  sam_putstr_err("minishell1 exited abnormally\n");
  return (-42);
}
