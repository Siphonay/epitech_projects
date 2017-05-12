//
// Banana.cpp for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d14m
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Tue Jan 17 09:39:03 2017 Alexis Viguié
// Last update Tue Jan 17 10:17:01 2017 Alexis Viguié
//

#include <string>
#include "Banana.h"

Banana::Banana() : Fruit::Fruit(5, "banana")
{
}

Banana::~Banana()
{
}

int	Banana::getVitamins()
{
  return (this->_vitamins);
}
