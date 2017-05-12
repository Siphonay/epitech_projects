//
// Lemon.cpp for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d14m
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Tue Jan 17 09:39:03 2017 Alexis Viguié
// Last update Tue Jan 17 10:15:53 2017 Alexis Viguié
//

#include <string>
#include "Lemon.h"

Lemon::Lemon() : Fruit::Fruit(3, "lemon")
{
}

Lemon::~Lemon()
{
}

int	Lemon::getVitamins()
{
  return (this->_vitamins);
}
