/*
** ConveyorBeltPePeNoel.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 17:04:14 2017 Alexandre Gaubert
** Last update	Sat Jan 14 23:00:02 2017 Alexandre Gaubert
*/

#include "IConveyorBelt.hh"
#include "Object.hh"
#include <string>
#include <cstdio>
#include <iostream>

#ifndef CONVEYORBELTPEPENOEl_HH_
#define CONVEYORBELTPEPENOEl_HH_

class ConveyorBeltPePeNoel : public IConveyorBelt {
private:
  /* data */
public:
  ConveyorBeltPePeNoel ();
  virtual ~ConveyorBeltPePeNoel ();
  ConveyorBeltPePeNoel(const ConveyorBeltPePeNoel &obj);
  ConveyorBeltPePeNoel  &operator=(const ConveyorBeltPePeNoel &obj);
  virtual std::string look() const;
  virtual int put(Object &obj);
  virtual std::string take();
  virtual std::string get();
};

#endif /* !CONVEYORBELTPEPENOEl_HH_ */
