//
// Fruit.cpp for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d14m
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Tue Jan 17 09:27:09 2017 Alexis Viguié
// Last update Tue Jan 17 10:16:38 2017 Alexis Viguié
//

#include <string>
#include "Fruit.h"

Fruit::Fruit()
{
  this->_vitamins = 0;
  this->_name = "fruit";
}

Fruit::Fruit(const int& vitamins, const std::string& name)
{
  this->_vitamins = vitamins;
  this->_name = name;
}

Fruit::~Fruit()
{
}

std::string	Fruit::getName()
{
  return (this->_name);
}
