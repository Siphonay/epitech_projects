/*
** help_message.c for SBMLparser in /home/sam/Rendu/Piscine_S/projet_1/SBMLparser
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Jun 14 10:54:22 2016 Alexis Viguié
** Last update Tue Jun 14 21:24:24 2016 Alexis Viguié
*/

#include <stdio.h>
#include "sbml.h"

int	print_help()
{
  printf("%s\n\t%s\n\n%s\n\t%s\n\t%s%s\n\t%s%s\n\t%s\n",
	 HELP_USAGE,
	 HELP_CLINE,
	 HELP_DESCRIPTION,
	 HELP_FILE,
	 HELP_I, HELP_I2,
	 HELP_E, HELP_E2,
	 HELP_JSON);
  return (SBML_EXIT_SUCCESS);
}
