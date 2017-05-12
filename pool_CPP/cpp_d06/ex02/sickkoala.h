//
// sickkoala.h for SickKoala in /home/sam/Rendu/Piscine_CPP/cpp_d06/ex02
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan  9 17:10:21 2017 Alexis Viguié
// Last update Mon Jan  9 18:52:14 2017 Alexis Viguié
//

#ifndef SICKKOALA_H_
# define SICKKOALA_H_

# include <string>

class		SickKoala
{
  std::string	name;

public:
  SickKoala(std::string name);
  ~SickKoala(void);
  void		poke(void);
  bool		takeDrug(std::string drug);
  void		overDrive(std::string msg);
};

#endif /* !SICKKOALA_H_ */
