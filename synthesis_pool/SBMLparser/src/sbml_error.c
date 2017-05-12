/*
** sbml_error.c for SBMLparsing in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Jun 14 21:26:54 2016 Alexis Viguié
** Last update Wed Jun 15 10:18:41 2016 Alexis Viguié
*/

#include <stdio.h>
#include "sbml.h"

int	sbml_error_handling(t_options options, char *filename)
{
  fprintf(stderr, "SBMLparser: ");
  if (options.noarg)
    fprintf(stderr, ERR_NOARG);
  else if (options.fd < 0)
    fprintf(stderr, ERR_NOFILE, filename);
  else if (options.help_afterarg)
    fprintf(stderr, ERR_HELP);
  else
    fprintf(stderr, ERR_STRING_OPTION, options.invalidarg);
  return (SBML_EXIT_FAILURE);
}
