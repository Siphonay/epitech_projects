/*
** Toy.cpp for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 11:44:29 2017 Alexandre Gaubert
** Last update	Sat Jan 14 13:04:11 2017 Alexandre Gaubert
*/

#include <cstdio>
#include <iostream>
#include "Object.hh"
#include "Toy.hh"

Toy::Toy(std::string const& title, std::string const & type) : Object(title, type)
{

}

/*Toy::Toy(Toy const & toy_): Object("","")
{
  this->title = toy_.getTitle();
  this->type = toy_.getType();
}*/

Toy::~Toy()
{
}

Toy::Toy(): Object("", "") {

}

Toy::Toy(const Toy &obj):Object(obj.title, obj.type) {

}

Toy &Toy::operator=(const Toy &obj) {
    this->title = obj.getTitle();
    this->type = obj.getType();
    return (*this);
}

