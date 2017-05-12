/*
** Teddy.cpp for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 11:45:23 2017 Alexandre Gaubert
** Last update	Sat Jan 14 13:03:31 2017 Alexandre Gaubert
*/
#include <cstdio>
#include <iostream>
#include "Teddy.hh"

Teddy::Teddy(const std::string & title, const std::string & type) : Toy(title, type)
{

}

Teddy::~Teddy()
{
  this->title.empty();
  this->type.empty();
  std::cout << "teddy dtor" << '\n';

}

Teddy::Teddy(const Teddy &obj) : Toy(obj.title, obj.type)
{
}

Teddy &Teddy::operator=(const Teddy &obj)
{
  this->title = obj.title;
  this->type = obj.type;
return (*this);
}

void Teddy::isTaken() {
  std::cout << "gra hu" << '\n';
}
