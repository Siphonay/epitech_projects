/*
** Object.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 12:14:06 2017 Alexandre Gaubert
** Last update	Sat Jan 14 13:01:18 2017 Alexandre Gaubert
*/

#include <cstdio>
#include <iostream>

#ifndef OBJECT_HH_
#define OBJECT_HH_

class Object {
protected:
  std::string title;
  std::string type;
public:
  Object(const std::string & title, const std::string & type);
  virtual ~Object ();
  Object(const Object &obj);
  Object  &operator=(const Object &obj);
  std::string const&getTitle() const;
  std::string const&getType() const;
};

Object **MyUnitTests();

#endif /* !OBJECT_HH_ */
