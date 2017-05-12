/*
** mtk_client.h for minitalk client in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.eu>
**
** Started on  Wed Feb 17 17:04:09 2016 Alexis Viguié
** Last update Wed Feb 17 17:32:30 2016 Alexis Viguié
*/

#ifndef MTK_CLIENT_H_
# define MTK_CLIENT_H_

void	client_send_char(char tosend_char, int pid);
void	client_fail_free_and_exit(char *str_tofree);

#endif /* !MTK_CLIENT_H_ */
