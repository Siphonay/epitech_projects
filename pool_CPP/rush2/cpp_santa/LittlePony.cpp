/*
** LittlePony.cpp for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 11:45:37 2017 Alexandre Gaubert
** Last update	Sat Jan 14 13:03:23 2017 Alexandre Gaubert
*/
#include <cstdio>
#include <iostream>
#include "LittlePony.hh"
#include "Toy.hh"

LittlePony::LittlePony(const std::string & title, const std::string & type) : Toy(title, type)
{

}

LittlePony::~LittlePony()
{
  this->title.empty();
  this->type.empty();
  std::cout << "littlepony dtor" << '\n';
}

LittlePony::LittlePony(LittlePony const &obj):Toy(obj.title, obj.type) {
}

LittlePony &LittlePony::operator=(const LittlePony &obj)
{
  this->title = obj.title;
  this->type = obj.type;
return (*this);
}

void LittlePony::isTaken() {
  std::cout << "yo man" << '\n';
}
