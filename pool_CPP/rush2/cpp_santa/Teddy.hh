/*
** Teddy.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 11:41:24 2017 Alexandre Gaubert
** Last update	Sat Jan 14 12:56:37 2017 Alexandre Gaubert
*/

#include "Toy.hh"

#ifndef TEDDY_HH_
#define TEDDY_HH_

class Teddy : public Toy {
private:
  /* data */
public:
  Teddy (const std::string & title, const std::string & type = "teddy");
  virtual ~Teddy ();
  Teddy(const Teddy &obj);
  Teddy  &operator=(const Teddy &obj);
  virtual void isTaken();
};

#endif /* !TEDDY_HH_ */
