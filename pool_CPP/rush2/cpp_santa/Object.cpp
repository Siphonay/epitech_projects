/*
** Object.cpp for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 12:15:07 2017 Alexandre Gaubert
** Last update	Sat Jan 14 13:03:54 2017 Alexandre Gaubert
*/

#include "Object.hh"
#include "Teddy.hh"
#include "LittlePony.hh"
#include <string>
#include <cstdio>
#include <iostream>

Object::Object(std::string const & title, std::string const & type)
{
  this->title = title;
  this->type = type;
}

Object::~Object()
{
  this->title.empty();
  this->type.empty();
  std::cout << "object dtor" << '\n';  
}

Object::Object(const Object &obj)
{
  (void) obj;
  this->title = obj.getTitle();
}

Object &Object::operator=(const Object &obj)
{
  (void)obj;
return (*this);
}

std::string const&Object::getTitle() const {
  return (this->title);
}

std::string const&Object::getType() const {
  return (this->type);
}

Object **MyUnitTests() {
  Object **objects = new Object *[2];

  objects[0] = new LittlePony("gay pony", "littlepony");
  objects[1] = new Teddy("bisounours", "teddy");

  return objects;
}
