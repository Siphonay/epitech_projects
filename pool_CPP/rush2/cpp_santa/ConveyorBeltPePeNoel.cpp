/*
** ConveyorBeltPePeNoel.cpp for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 21:56:59 2017 Alexandre Gaubert
** Last update	Sat Jan 14 22:59:32 2017 Alexandre Gaubert
*/

#include "ConveyorBeltPePeNoel.hh"
#include "Object.hh"
#include <string>
#include <cstdio>
#include <iostream>

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel()
{
  this->object = NULL;
  // for (unsigned int i = 0; i < 10; i++) { this->objects[i] = NULL; }
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel()
{
  this->object = NULL;
}

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel(const ConveyorBeltPePeNoel &obj)
{

}

std::string ConveyorBeltPePeNoel::look() const
{
  if (this->object != NULL)
    return this->object->getTitle();
  return NULL;
}

int ConveyorBeltPePeNoel::put(Object &obj){
  if (this->object == NULL) {
    this->object = &obj;
  }
}

std::string ConveyorBeltPePeNoel::take() {
  if (this->object != NULL) {
    std::string tmp = this->object->getTitle();
    this->object = NULL;
    return tmp;
  }
  return NULL;
}

std::string ConveyorBeltPePeNoel::get() {
  return this->object->getTitle();
}
