//
// Created by joa_b on 14/01/17.
//

#include "Object.hh"
#include "Wrap.hh"
#include "Teddy.hh"
#include "Box.hh"
#include "GiftPaper.hh"
#include "error.h"

Wrap::Wrap(std::string const &title, std::string const &type):Object(title, type) {
this->_istaken = false;
  this->_isopen = false;
  this->_iswrap= false;
  this->_isempty = false;
  this->_ispaper = false;
}

Wrap::~Wrap() {

}

bool	Wrap::ternaryCondition(Object *o) {
  return (this->_isempty) ? (EXCEPTION2("The box is empty"), false) :
    (!o) ? (EXCEPTION2("No toy to wrap"), false) :
    (!this->_ispaper) ? (EXCEPTION2("Not enough GiftPaper"), false) :
    (this->_isopen) ? (EXCEPTION2("You must close the box"), false) :
    (this->_iswrap) ? (EXCEPTION2("The box is already wrap"), false) :
    true;
}

bool Wrap::wrapMeThat(Object *o) {
    bool result = this->ternaryCondition(o);
  if (!result) return !result;

  this->_istaken = false;
  this->_inbox = o;
  this->_isempty = false;
  this->_iswrap = true;
  this->_isopen = false;
  std::cout << "tuuuut tuuut tuut" << std::endl;
  return true;
}

Object	*MyUnitTests(Object ** o)
{
  o[0] = new Teddy("bisounours", "teddy");
  o[1] = new Box("Gift", "box");
  o[2] = new GiftPaper("paper","papergift");
  o[3] = NULL;
  return (*o);
}
