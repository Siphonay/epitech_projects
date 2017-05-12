//
// koalanurse.h for koalanurse in /home/sam/Rendu/Piscine_CPP/cpp_d06/ex03
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan  9 19:00:41 2017 Alexis Viguié
// Last update Mon Jan  9 19:38:18 2017 Alexis Viguié
//
#ifndef KOALANURSE_H_
# define KOALANURSE_H_

# include <string>
# include "sickkoala.h"

class		KoalaNurse
{
  unsigned int	id;

public:
  KoalaNurse(unsigned int id);
  ~KoalaNurse(void);
  void		giveDrug(std::string drug, SickKoala patient);
  std::string	readReport(std::string file_name);
  void		timeCheck(void);
};

#endif /* !KOALANURSE_H_ */
