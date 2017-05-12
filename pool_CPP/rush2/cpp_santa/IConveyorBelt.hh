/*
** IConveyorBelt.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 16:07:18 2017 Alexandre Gaubert
** Last update	Sat Jan 14 23:00:07 2017 Alexandre Gaubert
*/

#include "Object.hh"

class IConveyorBelt {
protected:
  Object *object;
public:
  virtual std::string look() const = 0;
  virtual int put(Object &obj) = 0;
  virtual std::string take() = 0;
  virtual std::string get() = 0;
};
