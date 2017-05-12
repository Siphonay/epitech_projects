/*
** graph.h for bootstrap lemin in /home/sam/Rendu/Projets/projet_lemin/CPE_2015_lemin_bootstrap
**
** Made by
** Login   <sam@epitech.net>
**
** Started on  Wed Apr  6 14:01:51 2016
** Last update Thu Apr  7 09:40:53 2016 
*/

#ifndef LEMIN_BOOTSTRAP_H_
# define LEMIN_BOOTSTRAP_H_

typedef struct		s_maillon
{
  int			data;
  struct s_maillon	**next;
}			t_maillon;

t_maillon	*create_maillon(int data);
void		lb_putnbr(int nbr);
void		print_maillon(t_maillon *maillon);
void		link_maillon(t_maillon *maillon1, t_maillon *maillon2);
void		print_data_des_maillons_connexes(t_maillon *maillon);

#endif /* !LEMIN_BOOTSTRAP_H_ */
