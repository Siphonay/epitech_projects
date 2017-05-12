/*
** ITable.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 16:06:17 2017 Alexandre Gaubert
** Last update	Sat Jan 14 22:25:16 2017 Alexandre Gaubert
*/

#include "Object.hh"
#include <cstdio>
#include <iostream>
#include <vector>

#ifndef ITABLE_HH_
#define ITABLE_HH_

class ITable {
protected:
  std::string objects[10];
  unsigned int _cObjs;
public:
  virtual int putObject(Object &obj) = 0;
  virtual std::string *look() = 0;
  virtual std::string takeObject() = 0;
};

#endif /* !ITABLE_HH_ */
