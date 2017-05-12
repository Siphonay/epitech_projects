/*
** Toy.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 11:40:17 2017 Alexandre Gaubert
** Last update	Sat Jan 14 12:57:32 2017 Alexandre Gaubert
*/

#include "Object.hh"

#ifndef TOY_HH_
#define TOY_HH_

class Toy : public Object {
private:
  /* data */
public:
  Toy(const std::string & title, const std::string & type);
    Toy();
  virtual ~Toy();
  Toy(const Toy &obj);
  Toy  &operator=(const Toy &obj);
};

#endif /* !TOY_HH_ */
