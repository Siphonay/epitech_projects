//
// Toy.cpp for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d13/ex00
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan 16 18:28:38 2017 Alexis Viguié
// Last update Mon Jan 16 18:54:15 2017 Alexis Viguié
//

#include <string>
#include "Toy.h"
#include "Picture.h"

Toy::Toy()
{
  Picture	picture;
  
  this->_type = BASIC_TOY;
  this->_name = std::string("toy");
  this->_picture = picture;
}

Toy::Toy(ToyType type, const std::string& name, const std::string& file)
{
  Picture	picture(file);
  
  this->_type = type;
  this->_name = name;
  this->_picture = picture;
}

Toy::ToyType	Toy::getType()
{
  return (this->_type);
}

std::string	Toy::getName()
{
  return (this->_name);
}

std::string	Toy::getAscii()
{
  return (this->_picture.data);
}

void	Toy::setName(const std::string& name)
{
  this->_name = name;
}

bool		Toy::setAscii(const std::string& file)
{
  Picture	picture(file);

  return (this->_picture.getPictureFromFile(file));
}
