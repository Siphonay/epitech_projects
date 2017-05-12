//
// Created by joa_b on 14/01/17.
//

#ifndef CPP_SANTA_WRAP_HH
#define CPP_SANTA_WRAP_HH

#include "Object.hh"

class Wrap : public Object {
    protected:
  Object *_inbox;
  bool	_istaken;
  bool _isopen;
  bool _iswrap;
  bool _isempty;
  bool _ispaper;
public:
  Wrap(std::string const &, std::string const&);
  virtual ~Wrap();
  virtual bool  wrapMeThat(Object *);
    bool	ternaryCondition(Object *o);
};

Object	*MyUnitTests(Object ** o);

#endif //CPP_SANTA_WRAP_HH
