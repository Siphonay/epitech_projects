/*
** marvin.c for marvin in /home/sam/Rendu/Rushes/rush_marvin/test
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Sat May 14 14:09:17 2016 Alexis Viguié
** Last update Sat May 14 15:06:53 2016 Alexis Viguié
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
  FILE	*file_pointer;
  char	*cmd;
  char	buffer[2048];

  if (ac != 2)
    return (1);
  if (!(cmd = malloc(sizeof(char) *
		     (strlen("cdecl explain ") + strlen(av[1]) + 1))))
    return (1);
  if (!(cmd = strcpy(cmd, "cdecl explain ")))
    return (1);
  if (!(cmd = strcat(cmd, av[1])))
    return (1);
  if (!(file_pointer = popen(cmd, "r")))
    return (1);
  fgets(buffer, 2048, file_pointer);
  printf("%s\n", strtok(strdup(buffer), "\n"));
  fclose(file_pointer);
  return (0);
}
