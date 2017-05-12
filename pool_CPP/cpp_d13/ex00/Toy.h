//
// Toy.h for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d13/ex00
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan 16 17:59:15 2017 Alexis Viguié
// Last update Mon Jan 16 18:29:36 2017 Alexis Viguié
//

#ifndef TOY_H_
# define TOY_H_

# include <string>
# include "Picture.h"

class		Toy
{
public:
  enum		ToyType
    {
      BASIC_TOY,
      ALIEN
    };
  ToyType	getType();
  std::string	getName();
  std::string	getAscii();
  void		setName(const std::string& name);
  bool		setAscii(const std::string& file);
  Toy();
  Toy(ToyType type, const std::string& name, const std::string& file);
private:
  ToyType	_type;
  std::string	_name;
  Picture	_picture;
};

#endif /* !TOY_H_ */
