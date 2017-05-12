/*
** parsing.c for champion parser in /home/merlin/rendu/CPE/CPE_2015_corewar
**
** Made by Victor Herlin
** Login   <merlin@epitech.net>
**
** Started on  Mon Mar 21 10:49:56 2016 Victor Herlin
** Last update Wed Mar 30 14:35:15 2016 Victor Herlin
*/

int	comment(char *buff, int i)
{
  char	*comment;
  int	x;

  x = 0;
  while (buff[my_strlen(COMMENT_CMD_STRING) + 1] != '\n')
    {
      comment[x] = buff[my_strlen(COMMENT_CMD_STRING) + 1];
      x++;
      i++;
    }
  return (i);
}

int	name(char *buff, int i)
{
  char	*name;
  int	x;

  x = 0;
  while (buff[my_strlen(NAME_CMD_STRING) + 1] != '\n')
    {
      name[x] = buff[my_strlen(NAME_CMD_STRING) + 1];
      x++;
      i++;
    }
  return (i);
}

int	file_parsing(char *file_buff)
{
  int	i;
  int	verif;
  char	*strings_compar;

  i = 0;
  while (file_buff[i] != '\0')
    {
      if (file_buff[i] == '.')
	{
	  if (my_strncmp(file_buff[i] , NAME_CMD_STRING, 5) = 0)
	    i = name(file_buff, i);
	  else if (my_strncmp(file_buff[i] , COMMENT_CMD_STRING, 8) = 0)
	    i = comment(file_buff, i);
	  else
	    return (0);
	}
      else if (file_buff[i] != '.')
	i++;
    }
  return (1);
}
